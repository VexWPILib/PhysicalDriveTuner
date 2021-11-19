// Copyright (c) VexWPIApi contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the VexWPIApi BSD license file in the root directory of this project.

#include "PhysicalDrivetrainTuningSelector.h"

namespace vpi {

  namespace ui {

    using namespace vpi;

    QLength wheelTrack = 17_in;
    QLength wheelDiameter = 3.25_in;

    const char *btnmMapWheelDiameter[] = {"-5", "-1", "+1", "+5", "WD", ""};
    const char *btnmMapWheelTrack[] = {"-5", "-1", "+1", "+5", "WT", ""};

    lv_obj_t *wdBtnm;
    lv_obj_t *wdLabel;
    lv_obj_t *wtBtnm;
    lv_obj_t *wtLabel;
    
    void btnmWheelDiameterEventHandler(lv_obj_t * obj, lv_event_t e){
      if(e == LV_EVENT_VALUE_CHANGED) {
        //const char * txt = lv_btnmatrix_get_active_btn_text(obj);
        int i = lv_btnmatrix_get_active_btn(obj);
        if(i == 0) {
          wheelDiameter = wheelDiameter - 0.05 * inch;
        } else if (i == 1) {
          wheelDiameter = wheelDiameter - 0.01 * inch;
        } else if (i == 2) {
          wheelDiameter = wheelDiameter + 0.01 * inch;
        } else if (i == 3) {
          wheelDiameter = wheelDiameter + 0.05 * inch;
        }
        char buffer [50];
        sprintf (buffer, "Wheel Diameter %.2f_in", wheelDiameter.convert(inch));
        lv_label_set_text(wdLabel, buffer);
      }
    }

    void btnmWheelTrackEventHandler(lv_obj_t * obj, lv_event_t e){
      if(e == LV_EVENT_VALUE_CHANGED) {
        //const char * txt = lv_btnmatrix_get_active_btn_text(obj);
        int i = lv_btnmatrix_get_active_btn(obj);
        if(i == 0) {
          wheelTrack = wheelTrack - 0.05 * inch;
        } else if (i == 1) {
          wheelTrack = wheelTrack - 0.01 * inch;
        } else if (i == 2) {
          wheelTrack = wheelTrack + 0.01 * inch;
        } else if (i == 3) {
          wheelTrack = wheelTrack + 0.05 * inch;
        }
        char buffer [50];
        sprintf (buffer, "Wheel Track %.2f_in", wheelTrack.convert(inch));
        lv_label_set_text(wtLabel, buffer);
      }
    }

    void physicalTuningInit(){
      // Set the full screen background to Black
      static lv_style_t style_screen;
      // LV_STYLE_BG_COLOR
      lv_style_set_bg_color(&style_screen, LV_STATE_DEFAULT, LV_COLOR_BLACK);
      lv_obj_add_style(lv_scr_act(),LV_OBJ_PART_MAIN, &style_screen);

      static lv_style_t style1;
      static lv_style_t style2;
      static lv_style_t style3;
      lv_style_set_bg_color(&style1, LV_STATE_DEFAULT, LV_COLOR_BLACK);
      lv_style_set_bg_color(&style1, LV_STATE_PRESSED, LV_COLOR_GRAY);
      lv_style_set_bg_color(&style2, LV_STATE_CHECKED | LV_STATE_FOCUSED | LV_STATE_DEFAULT, LV_COLOR_PURPLE);
      lv_style_set_text_color(&style3, LV_STATE_DEFAULT, LV_COLOR_WHITE);

      // Create the WheelBase button matrix
      wdBtnm = lv_btnmatrix_create(lv_scr_act(), NULL);
      lv_btnmatrix_set_map(wdBtnm, btnmMapWheelDiameter);
      lv_obj_set_size(wdBtnm, 300, 40);
      lv_obj_set_pos(wdBtnm, 0, 0);
      lv_obj_align(wdBtnm, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 10);
      lv_obj_set_event_cb(wdBtnm, btnmWheelDiameterEventHandler);
      lv_obj_add_style(wdBtnm,LV_BTNMATRIX_PART_BG, &style1);
      lv_obj_add_style(wdBtnm,LV_BTNMATRIX_PART_BTN, &style2);
      
      wdLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
      lv_label_set_text(wdLabel, "Wheel Diameter 3.25_in"); //sets label text
      lv_obj_align(wdLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 60); //set the position to center
      lv_obj_add_style(wdLabel,LV_LABEL_PART_MAIN, &style3);

      // Create the WheelBase button matrix
      wtBtnm = lv_btnmatrix_create(lv_scr_act(), NULL);
      lv_btnmatrix_set_map(wtBtnm, btnmMapWheelTrack);
      lv_obj_set_size(wtBtnm, 300, 40);
      lv_obj_set_pos(wtBtnm, 0, 0);
      lv_obj_align(wtBtnm, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 110);
      lv_obj_set_event_cb(wtBtnm, btnmWheelTrackEventHandler);
      lv_obj_add_style(wtBtnm,LV_BTNMATRIX_PART_BG, &style1);
      lv_obj_add_style(wtBtnm,LV_BTNMATRIX_PART_BTN, &style2);

      wtLabel = lv_label_create(lv_scr_act(), NULL); //create label and puts it on the screen
      lv_label_set_text(wtLabel, "Wheel Track 17_in"); //sets label text
      lv_obj_align(wtLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 160); //set the position to center
      lv_obj_add_style(wtLabel,LV_LABEL_PART_MAIN, &style3);
    }

  } // namespace ui
} // namespace vpi