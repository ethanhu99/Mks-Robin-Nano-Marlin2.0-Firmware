#ifndef _DRAW_UI_H
#define _DRAW_UI_H

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

#include <stdint.h>
#include <string.h>
#include "lvgl.h"
#include "../inc/tft_multi_language.h"
#include "../inc/draw_ready_print.h"
#include "../inc/draw_language.h"
#include "../inc/draw_set.h"
#include "../inc/draw_tool.h"
#include "../inc/draw_print_file.h"
#include "../inc/draw_dialog.h"
#include "../inc/draw_printing.h"
#include "../inc/draw_opration.h"
#include "../inc/draw_preHeat.h"
#include "../inc/draw_extrusion.h"
#include "../inc/draw_home.h"
#include "../inc/draw_move_motor.h"
#include "../inc/draw_fan.h"
#include "../inc/draw_about.h"
#include "../inc/draw_change_speed.h"
#include "../inc/draw_manuaLevel.h"
#include "../inc/draw_error_message.h"
#include "../inc/printer_opration.h"
#include "../inc/draw_machine_para.h"
#include "../inc/draw_machine_settings.h"
#include "../inc/draw_motor_settings.h"
#include "../inc/draw_advance_settings.h"
#include "../inc/draw_acceleration_settings.h"
#include "../inc/draw_number_key.h"
#include "../inc/draw_jerk_settings.h"
#include "../inc/draw_pause_position.h"
#include "../inc/draw_step_settings.h"
#include "../inc/draw_tmc_current_settings.h"
#include "../inc/draw_eeprom_settings.h"
#include "../inc/draw_max_feedrate_settings.h"
#include "../inc/draw_tmc_step_mode_settings.h"


#include "../inc/wifiSerial.h"
#include "../inc/wifi_module.h"
#include "../inc/wifi_upload.h"
#include "../inc/draw_wifi_settings.h"
#include "../inc/draw_keyboard.h"
#include "../inc/draw_wifi.h"
#include "../inc/draw_wifi_list.h"
#include "../inc/draw_wifi_tips.h"

#define FILE_SYS_USB	0
#define FILE_SYS_SD	1

#define TICK_CYCLE 1

#define PARA_SEL_ICON_TEXT_COLOR	LV_COLOR_MAKE(0x4a, 0x52, 0xff);

#define  TFT35

#ifdef TFT35

#define TFT_WIDTH   480
#define TFT_HEIGHT   320

#define titleHeight	36//TFT_screen.title_high
#define INTERVAL_H	2//TFT_screen.gap_h// 2
#define INTERVAL_V	2//TFT_screen.gap_v// 2
#define BTN_X_PIXEL	117		//TFT_screen.btn_x_pixel//
#define BTN_Y_PIXEL	140//TFT_screen.btn_y_pixel//

#define SIMPLE_FIRST_PAGE_GRAP		30

#define BUTTON_TEXT_Y_OFFSET		-10

#define TITLE_XPOS	 3		//TFT_screen.title_xpos//
#define TITLE_YPOS	 5		//TFT_screen.title_ypos//

#define FILE_BTN_CNT    6

#define OTHER_BTN_XPIEL		117
#define OTHER_BTN_YPIEL		92

#define FILE_PRE_PIC_X_OFFSET	8
#define FILE_PRE_PIC_Y_OFFSET	0

#define PREVIEW_LITTLE_PIC_SIZE		40910//400*100+9*101+1
#define PREVIEW_SIZE			202720//(PREVIEW_LITTLE_PIC_SIZE+800*200+201*9+1)

#define GCFG_FLAG_VALUE 0xef

//machine parameter ui
#define PARA_UI_POS_X	10
#define PARA_UI_POS_Y	50

#define PARA_UI_SIZE_X	450
#define PARA_UI_SIZE_Y	40

#define PARA_UI_ARROW_V	12

#define PARA_UI_BACL_POS_X		400
#define PARA_UI_BACL_POS_Y		270

#define PARA_UI_TURN_PAGE_POS_X		320
#define PARA_UI_TURN_PAGE_POS_Y		270

#define PARA_UI_VALUE_SIZE_X	370
#define PARA_UI_VALUE_POS_X	400
#define PARA_UI_VALUE_V	5

#define PARA_UI_STATE_POS_X	380
#define PARA_UI_STATE_V		2


#else

#define TFT_WIDTH   320
#define TFT_HEIGHT   240

#endif

extern char public_buf_m[100];
extern char public_buf_l[30];

typedef struct
{
	uint8_t spi_flash_flag;
	uint8_t multiple_language;
	uint8_t language;
	uint8_t leveling_mode;
	uint8_t from_flash_pic;
	uint8_t finish_power_off;
	uint8_t pause_reprint;
	uint8_t wifi_mode_sel;
	uint8_t fileSysType;
	uint8_t wifi_type;
	bool  cloud_enable;
	float pausePosX;
	float pausePosY;
	float pausePosZ;
	uint32_t curFilesize;
	
}CFG_ITMES;

typedef struct
{
	uint8_t curTempType:1,
			curSprayerChoose:3,
			stepHeat:4;
	uint8_t leveling_first_time:1,
			para_ui_page:1,
			configWifi:1,
			command_send:1;
	uint8_t wifi_name[32];
	uint8_t wifi_key[64];
	uint8_t cloud_hostUrl[96];
	uint8_t extruStep;
	uint8_t extruSpeed;
	uint8_t print_state;
	uint8_t stepPrintSpeed;
	uint8_t waitEndMoves;
	uint8_t dialogType;
	uint16_t moveSpeed;
	uint16_t cloud_port;
	uint32_t totalSend;
	float   move_dist;
}UI_CFG;

typedef enum
{
	MAIN_UI,
	PRINT_READY_UI,
	PRINT_FILE_UI,
	PRINTING_UI,
	MOVE_MOTOR_UI,
	OPERATE_UI,
	PAUSE_UI,
	EXTRUSION_UI,
	FAN_UI,
	PRE_HEAT_UI,
	CHANGE_SPEED_UI,
	TEMP_UI,
	SET_UI,
	ZERO_UI,
	SPRAYER_UI,
	MACHINE_UI,
	LANGUAGE_UI,
	ABOUT_UI,
	LOG_UI,
	DISK_UI,
	CALIBRATE_UI,
	DIALOG_UI,
	WIFI_UI,
	MORE_UI,
	FILETRANSFER_UI,
	FILETRANSFERSTATE_UI,
	PRINT_MORE_UI,
	FILAMENTCHANGE_UI,
	LEVELING_UI,
	MESHLEVELING_UI,
	BIND_UI,
	ZOFFSET_UI,
	TOOL_UI,
	HARDWARE_TEST_UI,
	WIFI_LIST_UI,
	KEY_BOARD_UI,
	WIFI_TIPS_UI,
	MACHINE_PARA_UI,
	MACHINE_SETTINGS_UI,
	TEMPERATURE_SETTINGS_UI,
	MOTOR_SETTINGS_UI,
	MACHINETYPE_UI,
	STROKE_UI,
	HOME_DIR_UI,
	ENDSTOP_TYPE_UI,
	FILAMENT_SETTINGS_UI,
	LEVELING_SETTIGNS_UI,
	LEVELING_PARA_UI,
	DELTA_LEVELING_PARA_UI,
	XYZ_LEVELING_PARA_UI,
	MAXFEEDRATE_UI,
	STEPS_UI,
	ACCELERATION_UI,
	JERK_UI,
	MOTORDIR_UI,
	HOMESPEED_UI,
	NOZZLE_CONFIG_UI,
	HOTBED_CONFIG_UI,
	ADVANCED_UI,
	DOUBLE_Z_UI,
	ENABLE_INVERT_UI,
	NUMBER_KEY_UI,
	BABY_STEP_UI,
	ERROR_MESSAGE_UI,
	PAUSE_POS_UI,
	TMC_CURRENT_UI,
	TMC_MODE_UI,
	EEPROM_SETTINGS_UI,
	WIFI_SETTINGS_UI
} DISP_STATE;

typedef struct
{
	DISP_STATE _disp_state[100];
	int       _disp_index;
	
} DISP_STATE_STACK;

typedef struct
{
	
	int16_t  days;    
	uint16_t    hours;
	uint8_t    minutes;
	volatile int8_t    seconds;
	int8_t    ms_10;
	int8_t	start;
	
} PRINT_TIME;
extern PRINT_TIME  print_time;

typedef enum
{
	PrintAcceleration,
	RetractAcceleration,
	TravelAcceleration,
	XAcceleration,
	YAcceleration,
	ZAcceleration,
	E0Acceleration,
	E1Acceleration,

	XMaxFeedRate,
	YMaxFeedRate,
	ZMaxFeedRate,
	E0MaxFeedRate,
	E1MaxFeedRate,

	XJerk,
	YJerk,
	ZJerk,
	EJerk,

	Xstep,
	Ystep,
	Zstep,
	E0step,
	E1step,

	Xcurrent,
	Ycurrent,
	Zcurrent,
	E0current,
	E1current,

	pause_pos_x,
	pause_pos_y,
	pause_pos_z	
}num_key_value_state;
extern num_key_value_state value;

typedef enum
{
	wifiName,
	wifiPassWord,
	wifiConfig
}keyboard_value_state;
extern keyboard_value_state keyboard_value;


extern CFG_ITMES gCfgItems;
extern UI_CFG uiCfg;
extern DISP_STATE disp_state;
extern DISP_STATE last_disp_state;
extern DISP_STATE_STACK disp_state_stack;

extern lv_style_t tft_style_scr;
extern lv_style_t tft_style_lable_pre;
extern lv_style_t tft_style_lable_rel;
extern lv_style_t style_line;
extern lv_style_t style_para_value_pre;
extern lv_style_t style_para_value_rel;
extern lv_style_t style_num_key_pre;
extern lv_style_t style_num_key_rel;
extern lv_style_t style_num_text;
extern lv_style_t style_sel_text;

extern lv_point_t line_points[4][2];

extern void gCfgItems_init();
extern void ui_cfg_init();
extern void tft_style_init();
extern char *creat_title_text(void);
extern void preview_gcode_prehandle(char *path);
extern void update_spi_flash();
extern void disp_pre_gcode(int xpos_pixel,int ypos_pixel);
extern void GUI_RefreshPage();
extern void clear_cur_ui();
extern void draw_return_ui();
extern void sd_detection();
extern void gCfg_to_spiFlah();
extern void print_time_count();

extern void LV_TASK_HANDLER();

extern void lv_ex_line(lv_obj_t * line,lv_point_t *points);

#if defined(__cplusplus)
}    /* Make sure we have C-declarations in C++ programs */
#endif

#endif
