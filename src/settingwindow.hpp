/*
    JaneClone - A bulletin board viewer for 5ch.io-like BBSs
    Copyright (C) 2012-2021 Hiroyuki Nagata
    Copyright (C) 2026- Hi-no-to-ri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Contributor:
        Hiroyuki Nagata <idiotpanzer@gmail.com>
        Hi-no-to-ri <https://github.com/Hi-no-to-ri>
*/

#ifndef SETTINGWINDOW_HPP
#define SETTINGWINDOW_HPP

#include <wx/wx.h>
#include <wx/image.h>
#include <wx/splitter.h>
#include <wx/treectrl.h>
#include <wx/xrc/xmlres.h>
#include <wx/notebook.h>
#include "enums.hpp"
#include "otherpanels.hpp"

class SettingDialog: public wxDialog
{

public:
    /**
     * 設定画面のコンストラクタ
     */
    SettingDialog(wxWindow* parent,
                  int id,
                  const wxString& title);

#ifdef __WXMAC__
    // リソースの更新を行う
    void UpdateResources() {
        wxBoxSizer* vbox = new wxBoxSizer(wxVERTICAL);
        vbox->Add(new NetworkSettingPanel(settingPanel));
        settingPanel->SetSizer(vbox);
    };
#endif


private:
    void SetProperties();
    void DoLayout();
    void OnQuit(wxCommandEvent& event);
    void OnChangeSettingPanel(wxTreeEvent& event);
    void SaveConfig(const wxString& title);

#ifdef __WXMAC__
    // メインのスレッドにイベントを送る
    void SendUIUpdateEvent() {
        wxCommandEvent* event = new wxCommandEvent(wxEVT_UPDATE_UI, ID_SettingPanelUpdate);
        wxString ui = wxT("SettingDialog");
        event->SetString(ui.c_str());
        event->SetEventObject(this);

#if wxCHECK_VERSION(2, 9, 0)
        wxTheApp->GetTopWindow()->GetEventHandler()->QueueEvent(event->Clone());
#else
        this->GetEventHandler()->AddPendingEvent(*event);
#endif
    };
#endif

protected:
    wxTreeCtrl* settingTreeCtrl;
    wxPanel* treePanel;
    wxPanel* settingPanel;
    wxSplitterWindow* splitterWindow;
    wxPanel* spacePanel;
    wxButton* okButton;
    wxButton* cancelButton;
    wxPanel* bottomPanel;
    DECLARE_EVENT_TABLE()
};

/**
 * ビューア設定画面
 */
class ViewerSettingDialog: public wxDialog
{

public:
    /**
     * ビューア設定画面のコンストラクタ
     */
    ViewerSettingDialog(wxWindow* parent,
                        int id,
                        const wxString& title);

private:
    void SetProperties();
    void DoLayout();
    void OnQuit(wxCommandEvent& event);
    void OnChangeSettingPanel(wxNotebookEvent& event);
    void SaveConfig(const wxString& title);

protected:
    wxPanel* bottomPanel;
    wxNotebook* settingNoteBook;
    wxPanel* settingPanel;
    wxPanel* spacePanel;
    wxButton* okButton;
    wxButton* cancelButton;
    DECLARE_EVENT_TABLE()
};

#endif // SETTINGWINDOW_H
