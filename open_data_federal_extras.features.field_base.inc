<?php
/**
 * @file
 * open_data_federal_extras.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function open_data_federal_extras_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_odfe_bureau_code'
  $field_bases['field_odfe_bureau_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_odfe_bureau_code',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'field_odfe_bureau_code_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
