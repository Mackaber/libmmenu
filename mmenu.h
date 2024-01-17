#ifndef menu_h__
#define menu_h__

#include <SDL/SDL.h>

// Existing enum definitions
typedef enum MenuReturnStatus {
    kStatusContinue = 0,
    kStatusSaveSlot = 1,
    kStatusLoadSlot = 11,
    kStatusOpenMenu = 23,
    kStatusChangeDisc = 24,
    kStatusExitGame = 31,
} MenuReturnStatus;

typedef enum MenuReturnEvent {
	kMenuEventKeyDown = 0,
    kMenuEventKeyUp = 1,
} MenuReturnEvent;

// Function pointer type for ShowMenu
typedef MenuReturnStatus (*ShowMenu_t)(char* rom_path, char* save_path_template, SDL_Surface* frame, MenuReturnEvent keyEvent);

// Function pointer type for ShowMenuWithAutoSave
typedef MenuReturnStatus (*ShowMenuWithAutoSave_t)(char* rom_path, char* save_path_template, char* autosave_path, SDL_Surface* frame, MenuReturnEvent keyEvent);

// Function prototypes
MenuReturnStatus ShowMenu(char* rom_path, char* save_path_template, SDL_Surface* frame, MenuReturnEvent keyEvent);
MenuReturnStatus ShowMenuWithAutoSave(char* rom_path, char* save_path_template, char* autosave_path, SDL_Surface* frame, MenuReturnEvent keyEvent);

// Existing function pointer types and prototypes
typedef int (*ResumeSlot_t)(void);
int ResumeSlot(void);

typedef int (*ChangeDisc_t)(char* disc_path);
int ChangeDisc(char* disc_path);

#endif  // menu_h__
