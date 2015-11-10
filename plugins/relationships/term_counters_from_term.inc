<?php

/**
 * @file
 * Plugin to provide an relationship handler for taxonomy term counters from taxonomy term.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Term counters from term'),
  'keyword' => 'term_counters',
  'description' => t('Provide taxonomy term counters context for term context.'),
  'required context' => new ctools_context_required(t('Term'), 'entity:taxonomy_term'),
  'context' => 'ikto_taxonomy_counters_term_counters_from_term_context',
  'edit form' => 'ikto_taxonomy_counters_term_counters_from_term_settings_form',
  'defaults' => array(),
);

/**
 * Return a new context based on an existing context.
 */
function ikto_taxonomy_counters_term_counters_from_term_context($context, $conf) {
  // If unset it wants a generic, unfilled context, which is just NULL.
  if (empty($context->data)) {
    return ctools_context_create_empty('term_counters');
  }

  $taxonomy_term = $context->data;

  return ctools_context_create('term_counters', array('tid' => $taxonomy_term->tid));
}

/**
 * Settings form for the relationship.
 */
function ikto_taxonomy_counters_term_counters_from_term_settings_form($form, &$form_state) {
  $conf = $form_state['conf'];

  return $form;
}
