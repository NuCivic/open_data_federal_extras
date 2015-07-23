<?php
/**
 * @file
 * open_data_federal_extras.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function open_data_federal_extras_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_odfie_pod|node|dataset|default';
  $field_group->group_name = 'group_odfie_pod';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Open Data Fields',
    'weight' => '5',
    'children' => array(
      0 => 'field_odfe_bureau_code',
      1 => 'field_odfe_landing_page',
      2 => 'field_odfe_program_code',
      3 => 'field_odfe_rights',
      4 => 'field_odfe_conforms_to',
      5 => 'field_odfe_data_quality',
      6 => 'field_odfe_is_part_of',
      7 => 'field_odfe_language',
      8 => 'field_odfe_investment_uii',
      9 => 'field_odfe_system_of_records',
      10 => 'field_odfe_category',
    ),
    'format_type' => 'table',
    'format_settings' => array(
      'label' => 'Project Open Data Fields',
      'instance_settings' => array(
        'label' => 'hide',
        'desc' => 'These fields are compatible with <a href="https://project-open-data.cio.gov/">Project Open Data</a>, an Open Data policy of the US Federal government.',
        'first_column' => '',
        'second_column' => '',
        'cells' => 'empty',
      ),
    ),
  );
  $export['group_odfie_pod|node|dataset|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_odfie_pod|node|dataset|form';
  $field_group->group_name = 'group_odfie_pod';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'dataset';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Project Open Data Fields',
    'weight' => '3',
    'children' => array(
      0 => 'field_odfe_bureau_code',
      1 => 'field_odfe_landing_page',
      2 => 'field_odfe_program_code',
      3 => 'field_odfe_rights',
      4 => 'field_odfe_conforms_to',
      5 => 'field_odfe_data_quality',
      6 => 'field_odfe_is_part_of',
      7 => 'field_odfe_language',
      8 => 'field_odfe_investment_uii',
      9 => 'field_odfe_system_of_records',
      10 => 'field_odfe_category',
      11 => '_add_existing_field',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Project Open Data Fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-odfie-pod field-group-fieldset',
        'description' => 'These are fields that are specific to <a href="https://project-open-data.cio.gov">Project Open Data</a>.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_odfie_pod|node|dataset|form'] = $field_group;

  return $export;
}
