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

#include "janecloneuiutil.hpp"
#include "enums.hpp"
#include "janecloneutil.hpp"
#include "janeclone.hpp"

/**
 * wxTreeCtrlのインスタンスを受け取って共通の設定を行う
 *
 * @param wxTreeCtrl* treeCtrl 設定対象のツリー
 * @param const wxWindowID id  設定対象のGUIの部位を表すID
 */
void JaneCloneUiUtil::SetTreeCtrlCommonSetting(wxTreeCtrl* treeCtrl, const wxWindowID id)
{
    // プロパティファイルにフォント設定/背景色があれば使用する
    wxString widgetsName = wxT("ID_TreeFontButton");
    wxString widgetsInfo = wxEmptyString;
    JaneCloneUtil::GetJaneCloneProperties(widgetsName, &widgetsInfo);
    if (widgetsInfo != wxEmptyString)
        {
            wxFont font;
            bool ret = font.SetNativeFontInfoUserDesc(widgetsInfo);
            if(ret) treeCtrl->SetFont(font);
        }
    widgetsName = wxT("ID_BoardListBGColorButton");
    widgetsInfo.Clear();
    JaneCloneUtil::GetJaneCloneProperties(widgetsName, &widgetsInfo);
    if (widgetsInfo != wxEmptyString)
        {
            wxColour bgColor;
            bool ret = bgColor.Set(widgetsInfo);
            if(ret) treeCtrl->SetBackgroundColour(bgColor);
        }

    wxTreeItemData treeData;
    wxTreeItemId m_rootId;

    // イメージリストにアイコンを登録する
    wxImageList* treeImage = new wxImageList(16, 16);
    wxBitmap idx1(folderImg(), wxBITMAP_TYPE_PNG);
    treeImage->Add(idx1);
    wxBitmap idx2(textHtmlImg(), wxBITMAP_TYPE_PNG);
    treeImage->Add(idx2);
    treeCtrl->AssignImageList(treeImage);

    // ツリー部分へのカーソル合わせが起きた場合のイベント通知
    treeCtrl->Connect(id,
                      wxEVT_ENTER_WINDOW,
                      wxMouseEventHandler(JaneClone::OnEnterWindow),
                      NULL, wxWindow::FindWindowById(ID_WxJaneClone));

    switch (id)
        {

        case ID_BoardTreectrl:
            {
                treeCtrl->SetLabel(BOARD_TREE);
                wxTreeItemId rootTemp = treeCtrl->AddRoot(wxT("2ch板一覧"));
                treeCtrl->SetItemImage(rootTemp, 0, wxTreeItemIcon_Normal);
            }
            break;

        case ID_FavsTreectrl:
            {
                treeCtrl->SetLabel(FAVS_TREE);
                wxTreeItemId rootTemp = treeCtrl->AddRoot(wxT("お気に入り一覧"));
                treeCtrl->SetItemImage(rootTemp, 0, wxTreeItemIcon_Normal);
            }
            break;

        case ID_NowReadingTreectrl:
            {
                treeCtrl->SetLabel(NOW_READ_TREE);
                wxTreeItemId rootTemp = treeCtrl->AddRoot(wxT("閲覧中一覧"));
                treeCtrl->SetItemImage(rootTemp, 0, wxTreeItemIcon_Normal);
            }

            break;
        }
};


/**
 * wxWidgetsのイベント通知関数のラッパー
 *
 * @param const wxWindowID type
 * @param const wxWindowID id
 * @param const wxString&  m
 * @param wxObject* o
 */
void JaneCloneUiUtil::QueueEventHelper(const wxWindowID type, const wxWindowID id, const wxString& m, wxObject* o)
{
    wxCommandEvent* e = new wxCommandEvent(type, id);

    if (!m.IsEmpty()) {
        e->SetString(m.c_str());
    }

    if (o) {
        e->SetEventObject(o);
    }

#if wxCHECK_VERSION(2, 9, 0)
    wxTheApp->GetTopWindow()->GetEventHandler()->QueueEvent(e->Clone());
#else
    wxWindow::FindWindowById(ID_WxJaneClone)->AddPendingEvent(*e);
#endif
    delete e;
};


/**
 * JaneCloneのログ処理のラッパー
 *
 * @param const wxString& message
 */
void JaneCloneUiUtil::SendLoggingHelper(const wxString& message)
{
    JaneCloneUiUtil::QueueEventHelper(wxEVT_COMMAND_TEXT_UPDATED, ID_Logging, message);
};
