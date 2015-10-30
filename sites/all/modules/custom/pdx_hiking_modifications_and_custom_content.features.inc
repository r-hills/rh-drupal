<?php
/**
 * @file
 * pdx_hiking_modifications_and_custom_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pdx_hiking_modifications_and_custom_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pdx_hiking_modifications_and_custom_content_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pdx_hiking_modifications_and_custom_content_image_default_styles() {
  $styles = array();

  // Exported image style: hiking_photographs.
  $styles['hiking_photographs'] = array(
    'label' => 'hiking_photographs',
    'effects' => array(
      1 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 500,
          'height' => 600,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: hiking_slideshow.
  $styles['hiking_slideshow'] = array(
    'label' => 'hiking_slideshow',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pdx_hiking_modifications_and_custom_content_node_info() {
  $items = array(
    'blog_page' => array(
      'name' => t('Blog Page'),
      'base' => 'node_content',
      'description' => t('Here you will find scenic photographs of hikes around Oregon.'),
      'has_title' => '1',
      'title_label' => t('Gallery'),
      'help' => '',
    ),
    'slideshow_element' => array(
      'name' => t('Slideshow Element'),
      'base' => 'node_content',
      'description' => t('An entity for the slideshow page (not the home page slideshow)'),
      'has_title' => '1',
      'title_label' => t('Image Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
