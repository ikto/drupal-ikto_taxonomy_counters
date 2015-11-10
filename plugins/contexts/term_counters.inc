<?php

/**
 * @file
 *
 * Plugin to provide a taxonomy term counters context
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Term counters'),
  'description' => t('Counters related to taxonomy term.'),
  'context' => 'ikto_taxonomy_counters_context_create_term_counters',
  'edit form' => 'ikto_taxonomy_counters_context_term_counters_settings_form',
  'defaults' => array(
    'tid' => NULL,
  ),
  'keyword' => 'term_counters',
  'no ui' => FALSE,
  'context name' => 'term_counters',
  'convert' => 'ikto_taxonomy_counters_context_term_counters_convert',
  'convert list' => array(
    'count_terms'     => t('Count of child terms'),
    'count_nodes'     => t('count of child nodes'),
    'count_terms_all' => t('Count of child terms (including all nested)'),
    'count_nodes_all' => t('Count of child nodes (including all nested)'),
  ),
);

function ikto_taxonomy_counters_context_create_term_counters($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('term_counters');
  $context->plugin = 'term_counters';

  if ($empty) {
    return $context;
  }

  if (!empty($data['tid'])) {
    $query = db_select('ikto_taxonomy_counters', 'c');
    $query->fields('c', array('tid', 'count_terms', 'count_nodes', 'count_terms_all', 'count_nodes_all'));
    $query->condition('tid', $data['tid']);
    $result = $query->execute();

    if ($row = $result->fetchAssoc()) {
      $context->data = $row;
    }
  }

  return $context;
}

/**
 * Convert a context into a string.
 */
function ikto_taxonomy_counters_context_term_counters_convert($context, $type) {
  switch ($type) {
    case 'count_terms':
    case 'count_nodes':
    case 'count_terms_all':
    case 'count_nodes_all':
      return $context->data[$type];
      break;
  }
}

/**
 * Settings form
 */
function ikto_taxonomy_counters_context_term_counters_settings_form($form, &$form_state) {
  $conf = &$form_state['conf'];

  $form['tid'] = array(
    '#title' => t('Term ID'),
    '#type' => 'textfield',
    '#default_value' => $conf['tid'],
  );

  return $form;
}

function ikto_taxonomy_counters_context_term_counters_settings_form_submit($form, &$form_state) {
  foreach (array_keys($form_state['plugin']['defaults']) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
}
