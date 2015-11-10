<?php

function ikto_taxonomy_counters_settings_form($form, &$form_state) {
  $vocabularies = taxonomy_get_vocabularies();

  $form['ikto_taxonomy_counters_processing'] = array(
    '#type' => 'fieldset',
    '#title' => t('Processing settings'),
    '#collapsed' => FALSE,
    '#collapsible' => TRUE,
  );

  $voc = &$form['ikto_taxonomy_counters_processing'];

  foreach ($vocabularies as $vocabulary) {
    $voc['ikto_taxonomy_counters_processing_voc_manip_' . $vocabulary->machine_name] = array(
      '#type' => 'select',
      '#title' => $vocabulary->name . ' (manual or programmatical editing)',
      '#default_value' => variable_get('ikto_taxonomy_counters_processing_voc_manip_' . $vocabulary->machine_name, 0),
      '#options' => array(
        0 => t('Disabled'),
        1 => t('One pass'),
        -1 => t('Process to the end'),
      ),
    );

    $voc['ikto_taxonomy_counters_processing_voc_cron_' . $vocabulary->machine_name] = array(
      '#type' => 'select',
      '#title' => $vocabulary->name . ' (cron invocation)',
      '#default_value' => variable_get('ikto_taxonomy_counters_processing_voc_cron_' . $vocabulary->machine_name, 0),
      '#options' => array(
        0 => t('Disabled'),
        1 => t('One pass'),
        -1 => t('Process to the end'),
      ),
    );
  }

  return system_settings_form($form);
}
