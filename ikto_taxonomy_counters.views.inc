<?php

/**
 * Implements hook_views_data().
 */
function ikto_taxonomy_counters_views_data() {
  $data['ikto_taxonomy_counters']['table']['group'] = t('Taxonomy term');

  $data['ikto_taxonomy_counters']['table']['join']['taxonomy_term_data'] = array(
    'left_field' => 'tid',
    'field' => 'tid',
  );

  $data['ikto_taxonomy_counters']['count_terms'] = array(
    'title' => t('Child terms count'),
    'help' => t('Counter: count of child terms'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ikto_taxonomy_counters']['count_nodes'] = array(
    'title' => t('Child nodes count'),
    'help' => t('Counter: count of child nodes'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ikto_taxonomy_counters']['count_terms_all'] = array(
    'title' => t('Child terms count (All)'),
    'help' => t('Counter: count of child terms (including all nested)'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['ikto_taxonomy_counters']['count_nodes_all'] = array(
    'title' => t('Child nodes count (All)'),
    'help' => t('Counter: count of child nodes (including all nested)'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  return $data;
}
