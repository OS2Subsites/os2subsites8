<?php
use Drupal\Core\Form\FormStateInterface;

function fds_fredericia_theme_form_system_theme_settings_alter(
  &$form,
  Drupal\Core\Form\FormStateInterface $form_state
) {
  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  $form['footer']['footer_show_latest_content'] = [
    '#type' => 'checkbox',
    '#title' => t('Show latest content section'),
    '#default_value' => theme_get_setting('footer_show_latest_content'),
  ];
}
