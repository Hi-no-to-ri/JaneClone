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

#ifndef JANECLONEUIUTIL_HPP_
#define JANECLONEUIUTIL_HPP_

#include <wx/treectrl.h>
#include <wx/imaglist.h>
#include "datatype.hpp"
#include "enums.hpp"

/**
 * JaneCloneのUI操作用クラス
 */
class JaneCloneUiUtil {

public:
    /**
     * wxTreeCtrlのインスタンスを受け取って共通の設定を行う
     *
     * @param wxTreeCtrl* treeCtrl 設定対象のツリー
     * @param const wxWindowID id  設定対象のGUIの部位を表すID
     */
    void static SetTreeCtrlCommonSetting(wxTreeCtrl* treeCtrl, const wxWindowID id);
    /**
     * wxWidgetsのイベント通知関数のラッパー
     *
     * @param const wxWindowID type
     * @param const wxWindowID id
     * @param const wxString&   m          Message for event destination
     * @param wxObject* o          wxObject for event destination
     */
    void static QueueEventHelper(const wxWindowID type, const wxWindowID id, const wxString& m = wxEmptyString, wxObject* o = NULL);
    /**
     * JaneCloneのログ処理のラッパー
     *
     * @param const wxString& message
     */
    void static SendLoggingHelper(const wxString& message);
};

#endif /* JANECLONEUIUTIL_HPP_ */
