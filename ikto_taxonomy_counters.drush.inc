<?php

/**
 * Implements hook_drush_command().
 */
function ikto_taxonomy_counters_drush_command() {
  $commands = array();

  $commands['taxonomy-counters-update'] = array(
    'description' => dt('Update taxonomy counters'),
    'callback' => 'drush_ikto_taxonomy_counters_taxonomy_counters_update',
  );

  return $commands;
}

function drush_ikto_taxonomy_counters_taxonomy_counters_update() {
  while (TRUE) {
    $query = db_select('ikto_taxonomy_counters', 'c');
    $query->fields('c', array('tid'));
    $query->condition('c.needs_update', 1);
    $res = $query->execute();

    $tids = array();
    while ($row = $res->fetchAssoc()) {
      $tids[] = $row['tid'];
    }

    drush_print(dt('Got terms which are need update: @count', array('@count' => count($tids))));

    if (empty($tids)) {
      drush_print(dt('Exiting...'));
      break;
    }

    drush_print(dt('Proceeding...'));

    for ($i = 0; $i < count($tids); $i++) {
      _drush_ikto_taxonomy_counters_print_progress($i / count($tids));
      ikto_taxonomy_counters_update_counters_for_tid($tids[$i]);
    }
    drush_print('');
  }

  drush_print(dt('Updating process ended.'));
}

function _drush_ikto_taxonomy_counters_print_progress($ratio) {
  $percentage = floor($ratio * 100) . '%';
  $columns = drush_get_context('DRUSH_COLUMNS', 80);
  // Subtract 8 characters for the percentage, brackets, spaces and arrow.
  $progress_columns = $columns - 8;
  // If ratio is 1 (complete), the > becomes a = to make a full bar.
  $arrow = ($ratio < 1) ? '>' : '=';
  // Print a new line if ratio is 1 (complete). Otherwise, use a CR.
  $line_ending = ($ratio < 1) ? "\r" : "\n";

  // Determine the current length of the progress string.
  $current_length = floor($ratio * $progress_columns);
  $progress_string = str_pad('', $current_length, '=');

  $output  = '[';
  $output .= $progress_string . $arrow;
  $output .= str_pad('', $progress_columns - $current_length);
  $output .= ']';
  $output .= str_pad('', 5 - strlen($percentage)) . $percentage;
  $output .= $line_ending;

  print $output;
}
