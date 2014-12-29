/****************************************************************************
 * Custom dialog - Pgn browser
 *  Author:  Bill Forster
 *  License: MIT license. Full text of license is in associated file LICENSE
 *  Copyright 2010-2014, Bill Forster <billforsternz at gmail dot com>
 ****************************************************************************/
#ifndef PGN_DIALOG_H
#define PGN_DIALOG_H
#include <map>
#include <list>
#include "wx/spinctrl.h"
#include "wx/statline.h"
#include "wx/accel.h"
#include "SuspendEngine.h"
#include "GamesCache.h"
#include "GamesDialog.h"
#include "GameDocument.h"
#include "Repository.h"

// Control identifiers
enum
{
    ID_PGN_DIALOG_FILE      = 10000,
    ID_PGN_DIALOG_CLIPBOARD = 10001,
    ID_PGN_DIALOG_SESSION   = 10002,
    ID_BOARD2GAME           = 10003,
    ID_PGN_DIALOG_GAME_DETAILS  = 10004,
    ID_REORDER              = 10005,
    ID_ADD_TO_CLIPBOARD     = 10006,
    ID_SAVE_ALL_TO_A_FILE   = 10007,
    ID_PGN_DIALOG_GAME_PREFIX    = 10008,
    ID_PGN_DIALOG_PUBLISH    = 10009,
    ID_PGN_DIALOG_DATABASE   = 10010,
    ID_PGN_DIALOG_UTILITY1   = 10011,
    ID_PGN_DIALOG_UTILITY2   = 10012
};

class wxVirtualPgnListCtrl;


// PgnDialog class declaration
class PgnDialog: public GamesDialog
{    
public:
    GameDocument *GetCachedDocument( int idx );
    DB_GAME_INFO *GetCachedDbGameInfo( int idx );
    void GetCachedDocumentRaw( int idx, GameDocument &gd );
    std::map<int,GameDocument>     local_cache;
    std::list<int>                 stack;

    // Constructors
    PgnDialog
    (
        wxWindow    *parent,
        GamesCache  *gc,
        GamesCache  *gc_clipboard,
        wxWindowID  id,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
    );
    
    // Overrides
    virtual void AddExtraControls();
    virtual void GetButtonGridDimensions( int &row1, int &col1, int &row2, int &col2 ) { row1=8; col1=2; row2=0; col2=0; }
    virtual void ReadItem( int item, DB_GAME_INFO &info );
    virtual void OnListColClick( int compare_col );
    virtual void OnSaveAllToAFile();
    virtual void OnHelpClick();
    virtual void OnSearch();
    virtual void OnUtility();
    virtual void OnCancel();
    virtual void OnNextMove( int idx );


    // Return true if a game has been selected
    bool LoadGame( GameLogic *gl, GameDocument& gd, int &file_game_idx );
    void SyncCacheOrderBefore();
    void SyncCacheOrderAfter();


    // PgnDialog member variables
public:

private:

    // Data members
    int file_game_idx;
};

#endif    // PGN_DIALOG_H
