// Copyright (c) 2023 Inaba (@hollyhockberry)
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php

#include <SPIFFS.h>
#include <M5Unified.h>

M5Canvas canvas;

void draw(float angle) {
  M5.Display.startWrite();
  canvas.pushRotateZoom(&M5.Display,
    canvas.width() / 2, canvas.height() / 2,
    angle, 1.f, 1.f);
  M5.Display.endWrite();
  M5.Display.waitDisplay();
}

void setup() {
  SPIFFS.begin();
  M5.begin();

  canvas.createSprite(240, 240);
  canvas.drawBmpFile(SPIFFS, "/jack.bmp");
  ::draw(0.f);
}

void loop() {
  const auto points = 150;
  for (auto i = 0; i < points; ++i) {
    auto f = (i / float(points - 1)) * 2 * PI;
    ::draw(::sin(f) * 30.f);
  }
}
