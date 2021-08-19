<?php

$info = [
  // Available colors and color labels used in theme.
  'fields' => [
    'background_color__default' => t('Background color - default'),
    'background_color__primary' => t('Background color - primary'),
    'background_color__secondary' => t('Background color - secondary (has white text)'),
    'background_color__tertiary' => t('Background color - tertiary (has white text)'),
    'background_color__navigation' => t('Background color - navigation  (has white text)'),
    'background_color__footer_primary' => t('Background color - footer primary (has white text)'),
    'background_color__footer_secondary' => t('Background color - footer secondary (has white text)'),
    'background_color__button' => t('Background color - button'),
    'background_color__button_hover' => t('Background color - button:hover'),
    'color__link' => t('Link color'),
    'color__link__hover' => t('Link:hover color'),
    'color__footer_link' => t('Footer link color'),
    'color__bullets' => t('Bullets color'),
  ],

  // Pre-defined color schemes.
  'schemes' => [
    'default' => [
      'title' => t('Standard (default)'),
      'colors' => [
        'background_color__default' => '#747474',
        'background_color__primary' => '#454545',
        'background_color__secondary' => '#1a1a1a',
        'background_color__tertiary' => '#004D99',
        'background_color__navigation' => '#004080',
        'background_color__footer_primary' => '#800080',
        'background_color__footer_secondary' => '#474748',
        'background_color__button' => '#999998',
        'background_color__button_hover' => '#999998',
        'color__link' => '#fffffe',
        'color__link__hover' => '#fffffe',
        'color__footer_link' => '#fffffe',
        'color__bullets' => '#fffffe',
      ],
    ],
  ],

  // CSS files (excluding @import) to rewrite with new color scheme.
  'css' => [
    'dist/stylesheets/stylesheet.css',
  ],

  // Files to copy.
  'copy' => [
    'logo.svg',
  ],
];
