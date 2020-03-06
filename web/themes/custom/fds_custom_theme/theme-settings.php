<?php

function fds_custom_theme_form_system_theme_settings_alter(
  &$form,
  Drupal\Core\Form\FormStateInterface $form_state
) {
  $form['social']['#access'] = FALSE;
}
