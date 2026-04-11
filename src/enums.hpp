// enums.hpp - janeclones' enums
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

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

#include "enumstring.hpp"
#include "datatype.hpp"

// テーブル要素
#define X_TABLE_ITEM(x) X(x, STR(x))

// 使いたい列挙型を定義する.バックスラッシュの後ろに文字があるとコンパイルエラーになるので注意
// -> 環境次第では一行コメントの末尾にバックスラッシュがあるだけでコンパイルエラーになるので修正
// -> それでも駄目そうだったので定義中のコメントを削除して末尾にまとめてIDと共に表にまとめた
#define X_TABLE \
X_TABLE_ITEM(ID_Restart)			\
X_TABLE_ITEM(ID_Test)				\
X_TABLE_ITEM(ID_Logging)			\
X_TABLE_ITEM(ID_WindowMinimize)			\
X_TABLE_ITEM(ID_GetBoardList)			\
X_TABLE_ITEM(ID_CheckLogDirectory)		\
X_TABLE_ITEM(ID_GetVersionInfo)			\
X_TABLE_ITEM(ID_WxJaneClone)                    \
X_TABLE_ITEM(ID_ThreadNoteBook)			\
X_TABLE_ITEM(ID_BoardNoteBook)			\
X_TABLE_ITEM(ID_ThumbnailNoteBook)		\
X_TABLE_ITEM(ID_BoardTreectrl)			\
X_TABLE_ITEM(ID_ShingetsuBoardTreectrl)		\
X_TABLE_ITEM(ID_FavsTreectrl)                   \
X_TABLE_ITEM(ID_NowReadingTreectrl)             \
X_TABLE_ITEM(ID_BoardTreeNoteBook)		\
X_TABLE_ITEM(ID_ThreadContentWindow)            \
X_TABLE_ITEM(ID_OneBoardTabClose)		\
X_TABLE_ITEM(ID_ExcepSelTabClose)		\
X_TABLE_ITEM(ID_AllBoardTabClose)		\
X_TABLE_ITEM(ID_AllLeftBoardTabClose)		\
X_TABLE_ITEM(ID_AllRightBoardTabClose)		\
X_TABLE_ITEM(ID_OnOpenBoardByBrowser)		\
X_TABLE_ITEM(ID_ReloadOneBoard)			\
X_TABLE_ITEM(ID_ReloadAllBoard)			\
X_TABLE_ITEM(ID_CopyBURLToClipBoard)		\
X_TABLE_ITEM(ID_CopyBTitleToClipBoard)		\
X_TABLE_ITEM(ID_CopyBBothDataToClipBoard)	\
X_TABLE_ITEM(ID_DeleteBSelectedDatFile)         \
X_TABLE_ITEM(ID_DeleteBAllDatFile) 		\
X_TABLE_ITEM(ID_DeleteBAllDatFileWithoutFav)	\
X_TABLE_ITEM(ID_CopyTURLToClipBoard)		\
X_TABLE_ITEM(ID_CopyTTitleToClipBoard)		\
X_TABLE_ITEM(ID_CopyTBothDataToClipBoard)	\
X_TABLE_ITEM(ID_CopyTContentsToClipBoard)	\
X_TABLE_ITEM(ID_CopyTAllToClipBoard)		\
X_TABLE_ITEM(ID_OneThreadTabClose)		\
X_TABLE_ITEM(ID_ExcepSelThreadTabClose)		\
X_TABLE_ITEM(ID_AllThreadTabClose)		\
X_TABLE_ITEM(ID_AllLeftThreadTabClose)		\
X_TABLE_ITEM(ID_AllRightThreadTabClose)		\
X_TABLE_ITEM(ID_OnOpenThreadByBrowser)		\
X_TABLE_ITEM(ID_SaveDatFile)			\
X_TABLE_ITEM(ID_SaveDatFileToClipBoard)		\
X_TABLE_ITEM(ID_DeleteDatFile)			\
X_TABLE_ITEM(ID_ReloadThisThread)		\
X_TABLE_ITEM(ID_CallResponseWindow)		\
X_TABLE_ITEM(ID_BoardListCtrl)			\
X_TABLE_ITEM(ID_ShingetsuBoardListCtrl)		\
X_TABLE_ITEM(ID_FontDialogBoardTree)		\
X_TABLE_ITEM(ID_FontDialogLogWindow)		\
X_TABLE_ITEM(ID_FontDialogBoardNotebook)	\
X_TABLE_ITEM(ID_FontDialogThreadNotebook)	\
X_TABLE_ITEM(ID_FontDialogThreadContents)	\
X_TABLE_ITEM(ID_URLWindowButton)		\
X_TABLE_ITEM(ID_UserLastClosedThreadMenuUp)	\
X_TABLE_ITEM(ID_UserLastClosedBoardMenuUp)	\
X_TABLE_ITEM(ID_UserLookingTabsMenuUp)		\
X_TABLE_ITEM(ID_CommonAuiToolBarUpdate)         \
X_TABLE_ITEM(ID_FavsTreectrlUpdate)             \
X_TABLE_ITEM(ID_NowReadingTreectrlUpdate)	\
X_TABLE_ITEM(ID_UserLookingTabsControl)		\
X_TABLE_ITEM(ID_MoveNextTab)                    \
X_TABLE_ITEM(ID_MovePrevTab)			\
X_TABLE_ITEM(ID_UserLookingTabsMenuClick)	\
X_TABLE_ITEM(ID_OnOpenJaneCloneOfficial)	\
X_TABLE_ITEM(ID_OnOpen2chViewerOfficial)	\
X_TABLE_ITEM(ID_ThreadContentSearchBar)		\
X_TABLE_ITEM(ID_ThreadSearchBar)		\
X_TABLE_ITEM(ID_BoardSearchBar)			\
X_TABLE_ITEM(ID_ShingetsuBoardSearchBar)	\
X_TABLE_ITEM(ID_FavsSearchBar)                  \
X_TABLE_ITEM(ID_NowReadingSearchBar)		\
X_TABLE_ITEM(ID_ThreadSearchBarCombo)		\
X_TABLE_ITEM(ID_BoardSearchBarCombo)		\
X_TABLE_ITEM(ID_FavsSearchBarCombo)             \
X_TABLE_ITEM(ID_NowReadingSearchBarCombo)	\
X_TABLE_ITEM(ID_ThreadSearchBoxDoSearch)        \
X_TABLE_ITEM(ID_BoardSearchBoxDoSearch)		\
X_TABLE_ITEM(ID_FavsSearchBoxDoSeach)           \
X_TABLE_ITEM(ID_NowReadingBoxDoSeach)		\
X_TABLE_ITEM(ID_SearchBoxUp)			\
X_TABLE_ITEM(ID_SearchBoxDown)			\
X_TABLE_ITEM(ID_SearchBoxCopy)			\
X_TABLE_ITEM(ID_SearchBoxCut)			\
X_TABLE_ITEM(ID_SearchBoxSelectAll)		\
X_TABLE_ITEM(ID_SearchBoxClear)			\
X_TABLE_ITEM(ID_SearchBoxNormalSearch)		\
X_TABLE_ITEM(ID_SearchBoxRegexSearch)		\
X_TABLE_ITEM(ID_SearchBarHide)			\
X_TABLE_ITEM(ID_FloatToolBar)			\
X_TABLE_ITEM(ID_SwitchSeparateXY)		\
X_TABLE_ITEM(ID_SwitchTwoThreePane)		\
X_TABLE_ITEM(ID_ShowBoardListTree)		\
X_TABLE_ITEM(ID_SwitchRightPane)		\
X_TABLE_ITEM(ID_CallSettingWindow)		\
X_TABLE_ITEM(ID_CallViewerSettingWindow)        \
X_TABLE_ITEM(ID_ResponseWindow)			\
X_TABLE_ITEM(ID_QuitResponseWindow)		\
X_TABLE_ITEM(ID_PostResponse)			\
X_TABLE_ITEM(ID_PostConfirmForm)		\
X_TABLE_ITEM(ID_TCBAutoReload)			\
X_TABLE_ITEM(ID_TCBRedResExtract)		\
X_TABLE_ITEM(ID_TCBRefresh)			\
X_TABLE_ITEM(ID_TCBScrollToNewRes)		\
X_TABLE_ITEM(ID_TCBStop)			\
X_TABLE_ITEM(ID_TCBResExtract)			\
X_TABLE_ITEM(ID_TCBNewThread)			\
X_TABLE_ITEM(ID_TCBBookMark)			\
X_TABLE_ITEM(ID_TCBDeleteLog)			\
X_TABLE_ITEM(ID_TCBClose)			\
X_TABLE_ITEM(ID_TCBNormalSearch)		\
X_TABLE_ITEM(ID_TCBHideSearchBar)		\
X_TABLE_ITEM(ID_TCBForward)			\
X_TABLE_ITEM(ID_TCBBackward)			\
X_TABLE_ITEM(ID_ThreadContentBarUpdate)		\
X_TABLE_ITEM(ID_CopyFromHtmlWindow)		\
X_TABLE_ITEM(ID_CopyURLFromHtmlWindow)		\
X_TABLE_ITEM(ID_ShowRawHtmlFromHtmlWindow)      \
X_TABLE_ITEM(ID_SelectAllTextHtmlWindow)	\
X_TABLE_ITEM(ID_SearchSelectWordByYahoo)	\
X_TABLE_ITEM(ID_SearchSelectWordByGoogle)	\
X_TABLE_ITEM(ID_SearchSelectWordByAmazon)	\
X_TABLE_ITEM(ID_SearchThreadBySelectWord)	\
X_TABLE_ITEM(ID_CallResponseWindowAnchor)	\
X_TABLE_ITEM(ID_CallResponseWindowQuote)	\
X_TABLE_ITEM(ID_HtmlSourceDebug)		\
X_TABLE_ITEM(ID_ImagePanel)		        \
X_TABLE_ITEM(ID_OneThumbnailTabClose)		\
X_TABLE_ITEM(ID_AllThumbnailTabClose)		\
X_TABLE_ITEM(ID_SaveAsImages)		        \
X_TABLE_ITEM(ID_SaveAsImagesAll)		\
X_TABLE_ITEM(ID_AllLeftThumbnailTabClose)	\
X_TABLE_ITEM(ID_AllRightThumbnailTabClose)	\
X_TABLE_ITEM(ID_SelectLeftThumbnailTab)		\
X_TABLE_ITEM(ID_SelectRightThumbnailTab)	\
X_TABLE_ITEM(ID_OnOpenImageByBrowser)		\
X_TABLE_ITEM(ID_OpenThreadGotImage)		\
X_TABLE_ITEM(ID_CopyImageURLToClipBoard)	\
X_TABLE_ITEM(ID_Rotate90AntiClockwise)          \
X_TABLE_ITEM(ID_Rotate90Clockwise)              \
X_TABLE_ITEM(ID_ZoomIn)                         \
X_TABLE_ITEM(ID_ZoomOut)                        \
X_TABLE_ITEM(ID_ResetImageOriginalSize)         \
X_TABLE_ITEM(ID_HideThumbnailTab)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_CHK) 		\
X_TABLE_ITEM(ID_OnClickMenuCOL_NUM)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_TITLE)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_RESP)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_CACHEDRES)	\
X_TABLE_ITEM(ID_OnClickMenuCOL_NEWRESP)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_INCRESP)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_MOMENTUM)	\
X_TABLE_ITEM(ID_OnClickMenuCOL_LASTUP)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_SINCE)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_OID)		\
X_TABLE_ITEM(ID_OnClickMenuCOL_BOARDNAME)	\
X_TABLE_ITEM(ID_OnCancelSetting)		\
X_TABLE_ITEM(ID_OnOkSetting)			\
X_TABLE_ITEM(ID_SettingPanelTree)		\
X_TABLE_ITEM(ID_SettingPanelUpdate)		\
X_TABLE_ITEM(ID_ViewerSettingNote)              \
X_TABLE_ITEM(ID_NetworkPanelUpdate)		\
X_TABLE_ITEM(ID_NetworkPanel)			\
X_TABLE_ITEM(ID_NetworkPanelUseProxy)		\
X_TABLE_ITEM(ID_NetworkPanelUseProxyCache)	\
X_TABLE_ITEM(ID_NetworkPanelBasicAuthUserName)	\
X_TABLE_ITEM(ID_NetworkPanelBasicAuthPassword)	\
X_TABLE_ITEM(ID_NetworkPanelProxyReceiveAddr)	\
X_TABLE_ITEM(ID_NetworkPanelProxyReceivePort)	\
X_TABLE_ITEM(ID_NetworkPanelProxySendAddr)	\
X_TABLE_ITEM(ID_NetworkPanelProxySendPort)	\
X_TABLE_ITEM(ID_NetworkPanelProxySSLAuthAddr)	\
X_TABLE_ITEM(ID_NetworkPanelProxySSLAuthPort)	\
X_TABLE_ITEM(ID_NetworkPanelBoardListURL)       \
X_TABLE_ITEM(ID_NetworkPanelReceiveBufferSize)  \
X_TABLE_ITEM(ID_NetworkPanelMaxConn)            \
X_TABLE_ITEM(ID_NetworkPanelUserAgent)          \
X_TABLE_ITEM(ID_PathSettingPanel) 		\
X_TABLE_ITEM(ID_BrowserCheck)			\
X_TABLE_ITEM(ID_BrowserPathTC)			\
X_TABLE_ITEM(ID_DirPickerBrowser)		\
X_TABLE_ITEM(ID_BoardListTC)			\
X_TABLE_ITEM(ID_DirPickerBoardList)		\
X_TABLE_ITEM(ID_SkinPathTC)			\
X_TABLE_ITEM(ID_DirPickerSkin)			\
X_TABLE_ITEM(ID_ClearBrowserPath)		\
X_TABLE_ITEM(ID_ClearBoardListPath)		\
X_TABLE_ITEM(ID_ClearSkinPath)			\
X_TABLE_ITEM(ID_BehaviorPanel)			\
X_TABLE_ITEM(ID_OpenBNewTabCheck)		\
X_TABLE_ITEM(ID_OnlyOneCategoryCheck)		\
X_TABLE_ITEM(ID_OpenTNewTabCheck)		\
X_TABLE_ITEM(ID_ThreadNewTabCombo)		\
X_TABLE_ITEM(ID_LastReadThreadPosCheck)		\
X_TABLE_ITEM(ID_ThreadJumpSetting)		\
X_TABLE_ITEM(ID_RedrawNewThreadCheck)		\
X_TABLE_ITEM(ID_ShowResponseCombo)		\
X_TABLE_ITEM(ID_FavoriteNewTabCheck)		\
X_TABLE_ITEM(ID_FavoriteOnlyOneFolder)		\
X_TABLE_ITEM(ID_ColorFontSettingPanel) 		\
X_TABLE_ITEM(ID_TreeSampleLabel)		\
X_TABLE_ITEM(ID_ThreadListSampleLabel)		\
X_TABLE_ITEM(ID_ExtractSampleLabel)		\
X_TABLE_ITEM(ID_LogWindowSampleLabel)		\
X_TABLE_ITEM(ID_ThreadTitleSampleLabel)		\
X_TABLE_ITEM(ID_ThreadViewSampleLabel)		\
X_TABLE_ITEM(ID_KakikoSampleLabel)		\
X_TABLE_ITEM(ID_MemoSampleLabel)		\
X_TABLE_ITEM(ID_HintSampleLabel)		\
X_TABLE_ITEM(ID_LinkSampleLabel)		\
X_TABLE_ITEM(ID_OthersSampleLabel)		\
X_TABLE_ITEM(ID_AllSampleLabel)			\
X_TABLE_ITEM(ID_TreeFontButton)			\
X_TABLE_ITEM(ID_ThreadListFontButton)		\
X_TABLE_ITEM(ID_ExtractFontButton)		\
X_TABLE_ITEM(ID_LogWindowFontButton)		\
X_TABLE_ITEM(ID_ThreadTitleFontButton)		\
X_TABLE_ITEM(ID_KakikoFontButton)		\
X_TABLE_ITEM(ID_MemoFontButton)			\
X_TABLE_ITEM(ID_HintFontButton)			\
X_TABLE_ITEM(ID_LinkFontButton)			\
X_TABLE_ITEM(ID_OthersFontButton)		\
X_TABLE_ITEM(ID_AllFontButton)			\
X_TABLE_ITEM(ID_BoardListBGColorButton)		\
X_TABLE_ITEM(ID_ThreadListBGColorButton)	\
X_TABLE_ITEM(ID_LogWindowBGColorButton)		\
X_TABLE_ITEM(ID_ThreadTitleBGColorButton)	\
X_TABLE_ITEM(ID_ThreadViewBGColorButton)	\
X_TABLE_ITEM(ID_MemoBGColorButton)		\
X_TABLE_ITEM(ID_HintBGColorButton)		\
X_TABLE_ITEM(ID_PopupBGColorButton)		\
X_TABLE_ITEM(ID_AllBGColorButton) 		\
X_TABLE_ITEM(ID_UserSettingPanel) 		\
X_TABLE_ITEM(ID_MaruUserID) 			\
X_TABLE_ITEM(ID_MaruUserPassword)			\
X_TABLE_ITEM(ID_MaruAutoLoginCheck)			\
X_TABLE_ITEM(ID_MaruLogoutButton)			\
X_TABLE_ITEM(ID_BEMailAddress)			\
X_TABLE_ITEM(ID_BEPassword) 		\
X_TABLE_ITEM(ID_TabColorSettingPanel) 		\
X_TABLE_ITEM(ID_ThreadTabColorCheck) 		\
X_TABLE_ITEM(ID_ActiveTabBGColorButton) 		\
X_TABLE_ITEM(ID_DefaultActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_ReadingActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_BrokenActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_CannotPostActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_UpdateActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_PartialContentActiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_DeactiveTabBGColorButton) 		\
X_TABLE_ITEM(ID_DefaultDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_ReadingDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_BrokenDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_CannotPostDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_UpdateDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_PartialContentDeactiveTabSampleLabel) 		\
X_TABLE_ITEM(ID_ThreadTabDefaultFontColorButton) 		\
X_TABLE_ITEM(ID_ThreadTabReadingFontColorButton) 		\
X_TABLE_ITEM(ID_ThreadTabBrokenFontColorButton) 		\
X_TABLE_ITEM(ID_ThreadTabCannotPostFontColorButton) 		\
X_TABLE_ITEM(ID_ThreadTabUpdateFontColorButton) 		\
X_TABLE_ITEM(ID_ThreadTabPartialContentFontColorButton) 		\
X_TABLE_ITEM(ID_AutoReloadSampleLabel) 		\
X_TABLE_ITEM(ID_AutoReloadFontColorButton) 		\
X_TABLE_ITEM(ID_TabControlSettingPanel) \
X_TABLE_ITEM(ID_TabControlSettingPanelOpenTabChoice) \
X_TABLE_ITEM(ID_TabControlSettingPanelOpenTabFromOtherTabChoice) \
X_TABLE_ITEM(ID_TabControlSettingPanelCloseThreadViewTabChoice) \
X_TABLE_ITEM(ID_TabControlSettingPanelCloseThreadTabChoice) \
X_TABLE_ITEM(ID_AddThreadFavorite)                \
X_TABLE_ITEM(ID_DelThreadFavorite)		  \
X_TABLE_ITEM(ID_AddBoardFavorite)		  \
X_TABLE_ITEM(ID_DelBoardFavorite)		  \
X_TABLE_ITEM(ID_AddAllThreadFavorite)             \
X_TABLE_ITEM(ID_ResponseWindowSageChk)            \
X_TABLE_ITEM(ID_ResponseWindowBeChk)              \
X_TABLE_ITEM(ID_ChangeUserLastAttached)           \
X_TABLE_ITEM(ID_ReloadThreadByName)               \
X_TABLE_ITEM(ID_NewBoardAddDialog)                \
X_TABLE_ITEM(ID_CallNewBoardAddDialog)            \
X_TABLE_ITEM(ID_OperationPanel)                   \
X_TABLE_ITEM(ID_KakikomiPanel)                    \
X_TABLE_ITEM(ID_DoePanel)                         \
X_TABLE_ITEM(ID_OtherSettingPanelOne)             \
X_TABLE_ITEM(ID_ResetBoardListTree)               \
X_TABLE_ITEM(ID_Receive_Timeout_Sec)              \
X_TABLE_ITEM(ID_Connection_Timeout_Sec)		  \
X_TABLE_ITEM(ID_JaneCloneEnumsEnd)

// 列挙型の実体をマクロで生成する
enum JANECLONE_ENUMS {
    ID_Quit = 1,
    #define X(Enum, String) Enum,
    X_TABLE
    #undef X
    ID_UserLastClosedThreadClick = 1000,  // ユーザーが最後に閉じたスレッドの情報をクリックした(動的なIDのため1000~)
    ID_UserLastClosedBoardClick	 = 1100,  // ユーザーが最後に閉じた板の情報をクリックした(動的なIDのため1100~)
    ID_UserFavoriteThreadClick	 = 1200,  // ユーザーがお気に入りに登録したスレッドの情報をクリックした(動的なIDのため1200~)
    ID_ThreadContentBar	 = 1500			  // ThreadContentBar自体のID(動的なIDのため1500~)
};


// 列挙型を文字列化
Begin_Enum_String( JANECLONE_ENUMS )
{
#define X(Enum, String) \
    Enum_String( Enum ) \

    X_TABLE
#undef X
}
End_Enum_String;

#endif /* ENUMS_HPP_ */

/* ID_Name : 説明
ID_Restart : 再起動
ID_Test : テスト用
ID_Logging : ログ出力制御用
ID_WindowMinimize : ウィンドウを最小化する
ID_GetBoardList : 板一覧情報取得
ID_CheckLogDirectory : 保存されているログをスレッド一覧に表示する
ID_GetVersionInfo : バージョン情報
ID_WxJaneClone : メインのウィンドウID
ID_ThreadNoteBook : スレッド一覧ノートブックに使うID
ID_BoardNoteBook : 板一覧用ノートブックに使うID
ID_ThumbnailNoteBook : 画像ビューア用ID
ID_BoardTreectrl : 板一覧ツリー用ID
ID_ShingetsuBoardTreectrl : 新月公開ノード一覧ツリー用ID
ID_FavsTreectrl : お気に入りツリー用ID
ID_NowReadingTreectrl : 閲覧中ツリー用ID
ID_BoardTreeNoteBook : 板一覧ツリーを載せるノートブックに使うID
ID_ThreadContentWindow : スレビュー画面用ID
ID_OneBoardTabClose : スレッド一覧タブをひとつ閉じる
ID_ExcepSelTabClose : 現在選択されていないスレッド一覧タブを閉じる
ID_AllBoardTabClose : すべてのスレッド一覧タブを閉じる
ID_AllLeftBoardTabClose : これより左のスレッド一覧タブをを閉じる
ID_AllRightBoardTabClose : これより右のスレッド一覧タブを閉じる
ID_OnOpenBoardByBrowser : スレッド一覧をブラウザで開く
ID_ReloadOneBoard : アクティブなスレッド一覧をひとつ更新する
ID_ReloadAllBoard : すべてのタブのスレッド一覧を更新する
ID_CopyBURLToClipBoard : 板のURLをクリップボードにコピーする
ID_CopyBTitleToClipBoard : 板のタイトルをクリップボードにコピーする
ID_CopyBBothDataToClipBoard : 板のURLとタイトルをクリップボードにコピーする
ID_DeleteBSelectedDatFile : 選択中のログを削除
ID_DeleteBAllDatFile : すべてのログを削除
ID_DeleteBAllDatFileWithoutFav : お気に入り以外のログを削除
ID_CopyTURLToClipBoard : スレッドのURLをクリップボードにコピーする
ID_CopyTTitleToClipBoard : スレッドのタイトルをクリップボードにコピーする
ID_CopyTBothDataToClipBoard : スレッドのURLとタイトルをクリップボードにコピーする
ID_CopyTContentsToClipBoard : スレッドの内容をクリップボードにコピーする
ID_CopyTAllToClipBoard : スレッドの内容, URL, タイトルをクリップボードにコピーする
ID_OneThreadTabClose : スレタブをひとつ閉じる
ID_ExcepSelThreadTabClose : 現在選択されていないスレタブを閉じる
ID_AllThreadTabClose : すべてのスレタブを閉じる
ID_AllLeftThreadTabClose : これより左のスレタブをを閉じる
ID_AllRightThreadTabClose : これより右のスレタブを閉じる
ID_OnOpenThreadByBrowser : スレッドをブラウザで開く
ID_SaveDatFile : datファイルに名前を付けて保存
ID_SaveDatFileToClipBoard : datをクリップボードにコピー
ID_DeleteDatFile : このログを削除
ID_ReloadThisThread : スレッドの再読み込み
ID_CallResponseWindow : 書き込み用のウィンドウを呼び出す
ID_BoardListCtrl : 板一覧リスト自体を表すID
ID_ShingetsuBoardListCtrl : 新月の板一覧リスト自体を表すID
ID_FontDialogBoardTree : 板一覧ツリー部分のフォントの指定を行う
ID_FontDialogLogWindow : ログ出力画面部分のフォントの指定を行う
ID_FontDialogBoardNotebook : スレッド一覧部分のフォントの指定を行う
ID_FontDialogThreadNotebook : スレッド画面部分のフォント設定を呼び出
ID_FontDialogThreadContents : スレッド内で使用するフォント設定を呼び
ID_URLWindowButton : URL入力ウィンドウのボタンを表すID
ID_UserLastClosedThreadMenuUp : ユーザーが最後に閉じたスレッドの情報を
ID_UserLastClosedBoardMenuUp : ユーザーが最後に閉じた板の情報を項目に
ID_UserLookingTabsMenuUp : ユーザーが現在見ているスレタブ・板タブ
ID_CommonAuiToolBarUpdate : Auiツールバーの更新を行う
ID_FavsTreectrlUpdate : お気に入りツリーの更新を行う
ID_NowReadingTreectrlUpdate : 閲覧中ツリーの更新を行う
ID_UserLookingTabsControl : ユーザーが現在フォーカスしているウィン
ID_MoveNextTab : 表示しているタブを移動する(次)
ID_MovePrevTab : 表示しているタブを移動する(前)
ID_UserLookingTabsMenuClick : ユーザーが現在見ているスレタブ・板タブ
ID_OnOpenJaneCloneOfficial : JaneClone公式サイトをブラウザで開く
ID_OnOpen2chViewerOfficial : ●公式サイトをブラウザで開く
ID_ThreadContentSearchBar : スレッド内容バーの検索ボックスのID
ID_ThreadSearchBar : スレッド検索ボックスのID
ID_BoardSearchBar : 板名検索ボックスのID
ID_ShingetsuBoardSearchBar : 新月の板名検索ボックスのID
ID_FavsSearchBar : お気に入りのデータ検索ボックスのID
ID_NowReadingSearchBar : 閲覧中のデータ検索ボックスのID
ID_ThreadSearchBarCombo : スレッド検索ボックスのコンボボックス
ID_BoardSearchBarCombo : 板名検索ボックスのコンボボックス
ID_FavsSearchBarCombo : お気に入りのデータ検索ボックスのコンボボックス
ID_NowReadingSearchBarCombo : 閲覧中のデータ検索ボックスのコンボボックス
ID_ThreadSearchBoxDoSearch : 検索ボックス(スレッド一覧)で検索ボタンを押す
ID_BoardSearchBoxDoSearch : 検索ボックス(板一覧)で検索ボタンを押す
ID_FavsSearchBoxDoSeach : 検索ボックス(お気に入り一覧)で検索ボタンを押す
ID_NowReadingBoxDoSeach : 検索ボックス(閲覧中一覧)で検索ボタンを押す
ID_SearchBoxUp : 検索ボックスで上に移動
ID_SearchBoxDown : 検索ボックスで下に移動
ID_SearchBoxCopy : 検索ボックスでコピー実行
ID_SearchBoxCut : 検索ボックスで切り取り実行
ID_SearchBoxSelectAll : 検索ボックスで全て選択
ID_SearchBoxClear : 検索ボックスをクリア
ID_SearchBoxNormalSearch : 検索ボックスで通常検索
ID_SearchBoxRegexSearch : 検索ボックスで正規表現検索
ID_SearchBarHide : 検索ボックスを隠す
ID_FloatToolBar : アイコン付きのツールバー自体のID
ID_SwitchSeparateXY : 縦⇔横分割切り替え
ID_SwitchTwoThreePane : ２⇔３ペイン切り替え
ID_ShowBoardListTree : 板一覧ツリー表示切り替え
ID_SwitchRightPane : 右側ペインの内容切り替え
ID_CallSettingWindow : 設定画面を呼び出す
ID_CallViewerSettingWindow : ビューア設定画面を呼び出す
ID_ResponseWindow
ID_QuitResponseWindow
ID_PostResponse
ID_PostConfirmForm
ID_TCBAutoReload
ID_TCBRedResExtract
ID_TCBRefresh
ID_TCBScrollToNewRes
ID_TCBStop
ID_TCBResExtract
ID_TCBNewThread
ID_TCBBookMark
ID_TCBDeleteLog
ID_TCBClose
ID_TCBNormalSearch
ID_TCBHideSearchBar : スレッド内容バーの内容を隠す
ID_TCBForward
ID_TCBBackward
ID_ThreadContentBarUpdate
ID_CopyFromHtmlWindow : HtmlWindowで選択しているテキストをクリップボードにコピーする
ID_CopyURLFromHtmlWindow : HtmlWindowで選択しているURLをクリップボードにコピーする
ID_ShowRawHtmlFromHtmlWindow : HtmlWindowでスレッドのHTMLソースを表示する
ID_SelectAllTextHtmlWindow : HtmlWindowでテキストを全て選択する
ID_SearchSelect
ID_SearchSelectWordByYahoo : 選択したテキストでヤフー検索
ID_SearchSelectWordByGoogle : 選択したテキストでGoogle検索
ID_SearchSelectWordByAmazon : 選択したテキストでAmazon検索
ID_SearchThreadBySelectWord : 選択したテキストでスレタイ検索
ID_CallResponseWindowAnchor : 書き込み用のウィンドウをアンカー付きで呼び出す
ID_CallResponseWindowQuote : 書き込み用のウィンドウをレス引用付きで呼び出す
ID_HtmlSourceDebug
ID_ImagePanel : 画像パネル
ID_OneThumbnailTabClose : 画像タブをひとつ閉じる
ID_AllThumbnailTabClose : すべての画像タブを閉じる
ID_SaveAsImages : 名前をつけて保存
ID_SaveAsImagesAll : すべて保存
ID_AllLeftThumbnailTabClose : これより左の画像タブをを閉じる
ID_AllRightThumbnailTabClose : これより右の画像タブを閉じる
ID_SelectLeftThumbnailTab : 左の画像タブに移動
ID_SelectRightThumbnailTab : 右の画像タブに移動
ID_OnOpenImageByBrowser : 画像をブラウザで開く
ID_OpenThreadGotImage : 画像取得元のスレッドを開く
ID_CopyImageURLToClipBoard : 画像URLをクリップボードにコピーする
ID_Rotate90AntiClockwise : 画像を90度左回転させる
ID_Rotate90Clockwise : 画像を90度右回転させる
ID_ZoomIn : 画像を拡大する
ID_ZoomOut : 画像を縮小する
ID_ResetImageOriginalSize : 画像のサイズを元に戻す
ID_HideThumbnailTab : 画像ビューアを隠す
ID_OnClickMenuCOL_CHK : 新着チェック
ID_OnClickMenuCOL_NUM : 番号
ID_OnClickMenuCOL_TITLE : タイトル
ID_OnClickMenuCOL_RESP : レス
ID_OnClickMenuCOL_CACHEDRES : 取得
ID_OnClickMenuCOL_NEWRESP : 新着
ID_OnClickMenuCOL_INCRESP : 増レス
ID_OnClickMenuCOL_MOMENTUM : 勢い
ID_OnClickMenuCOL_LASTUP : 最終取得
ID_OnClickMenuCOL_SINCE : SINCE
ID_OnClickMenuCOL_OID : 固有番号
ID_OnClickMenuCOL_BOARDNAME : 板
ID_OnCancelSetting : 設定画面をキャンセル
ID_OnOkSetting : 設定画面をOkで終了
ID_SettingPanelTree : 設定画面の描画を切り替える
ID_SettingPanelUpdate : 設定画面の更新をメインスレッドに伝える
ID_ViewerSettingNote : ビューア設定画面
ID_NetworkPanelUpdate : ネットワーク設定画面の更新をメインスレッドに伝える
ID_NetworkPanel : ネットワーク設定用画面
ID_NetworkPanelUseProxy : プロキシを使用するかどうか
ID_NetworkPanelUseProxyCache : プロキシでキャッシュを使用するかどうか
ID_NetworkPanelBasicAuthUserName : ベーシック認証のユーザー名
ID_NetworkPanelBasicAuthPassword : ベーシック認証のパスワード
ID_NetworkPanelProxyReceiveAddr : Proxy受信用アドレス
ID_NetworkPanelProxyReceivePort : Proxy受信用ポート
ID_NetworkPanelProxySendAddr : Proxy送信用アドレス
ID_NetworkPanelProxySendPort : Proxy送信用ポート
ID_NetworkPanelProxySSLAuthAddr : Proxy SSL認証用アドレス
ID_NetworkPanelProxySSLAuthPort : Proxy SSL認証用ポート
ID_NetworkPanelBoardListURL : ボード一覧取得URL
ID_NetworkPanelReceiveBufferSize : 受信バッファサイズ
ID_NetworkPanelMaxConn : 最大接続数
ID_NetworkPanelUserAgent : 2chにアクセスする時のユーザーエージェント
ID_PathSettingPanel : 各種パス設定用画面
ID_BrowserCheck : 使用するブラウザを指定するかどうか
ID_BrowserPathTC : ブラウザのパスをもつテキストコントロール
ID_DirPickerBrowser : ブラウザのパスを参照する
ID_BoardListTC : 板一覧リストを保持する場所をもつテキストコントロール
ID_DirPickerBoardList : 板一覧リストのパスを参照する
ID_SkinPathTC : スキン用のファイルのパスをもつテキストコントロール
ID_DirPickerSkin : スキン用ファイルのパスを参照する
ID_ClearBrowserPath : ブラウザパス設定値を削除
ID_ClearBoardListPath : 板一覧リストのパス設定値を削除
ID_ClearSkinPath : スキンのパス設定値を削除
ID_BehaviorPanel : 動作設定用パネル
ID_OpenBNewTabCheck : 新しいタブで板を開く
ID_OnlyOneCategoryCheck : カテゴリを一つしか開かない
ID_OpenTNewTabCheck : 新しいタブでスレを開く
ID_ThreadNewTabCombo : 新しいタブでスレを開く
ID_LastReadThreadPosCheck : 最後に見たスレの位置にジャンプ
ID_ThreadJumpSetting : 最後に見たスレの位置にジャンプ
ID_RedrawNewThreadCheck : 新着チェック時に既得レスを描き直す
ID_ShowResponseCombo : 既得スレの表示レス数
ID_FavoriteNewTabCheck : お気に入りを新しいタブで開く
ID_FavoriteOnlyOneFolder : お気に入りフォルダを一つしか開かない
ID_ColorFontSettingPanel : 色・フォント設定用画面
ID_TreeSampleLabel : ツリーサンプル
ID_ThreadListSampleLabel : スレ欄サンプル
ID_ExtractSampleLabel : 抽出サンプル
ID_LogWindowSampleLabel : ログ出力画面サンプル
ID_ThreadTitleSampleLabel : スレッドタイトルサンプル
ID_ThreadViewSampleLabel : スレビューサンプル
ID_KakikoSampleLabel : 書き込みサンプル
ID_MemoSampleLabel : メモ欄サンプル
ID_HintSampleLabel : ヒントサンプル
ID_LinkSampleLabel : リンクサンプル
ID_OthersSampleLabel : その他サンプル
ID_AllSampleLabel : ツリーフォント設定ボタン
ID_TreeFontButton : スレ欄フォント設定ボタン
ID_ThreadListFontButton : 抽出フォント設定ボタン
ID_ExtractFontButton : ログ出力画面フォント設定ボタン
ID_LogWindowFontButton : スレッドタイトルフォント設定ボタン
ID_ThreadTitleFontButton : 書き込みフォント設定ボタン
ID_KakikoFontButton : メモ欄フォント設定ボタン
ID_MemoFontButton : ヒントフォント設定ボタン
ID_HintFontButton : リンクフォント設定ボタン
ID_LinkFontButton : その他フォント設定ボタン
ID_OthersFontButton : すべてフォント設定ボタン
ID_AllFontButton : スレ欄背景色設定ボタン
ID_BoardListBGColorButton : 抽出背景色設定ボタン
ID_ThreadListBGColorButton : ログ出力画面背景色設定ボタン
ID_LogWindowBGColorButton : スレッドタイトル背景色設定ボタン
ID_ThreadTitleBGColorButton : スレビュー背景色設定ボタン
ID_ThreadViewBGColorButton : メモ欄背景色設定ボタン
ID_MemoBGColorButton : ヒント背景色設定ボタン
ID_HintBGColorButton : ポップアップ背景色設定ボタン
ID_PopupBGColorButton : すべての背景色設定ボタン
ID_AllBGColorButton
ID_UserSettingPanel
ID_MaruUserID
ID_MaruUserPassword
ID_MaruAutoLoginCheck
ID_MaruLogoutButton
ID_BEMailAddress
ID_BEPassword
ID_TabColorSettingPanel
ID_ThreadTabColorCheck
ID_ActiveTabBGColorButton
ID_DefaultActiveTabSampleLabel
ID_ReadingActiveTabSampleLabel
ID_BrokenActiveTabSampleLabel
ID_CannotPostActiveTabSampleLabel
ID_UpdateActiveTabSampleLabel
ID_PartialContentActiveTabSampleLabel
ID_DeactiveTabBGColorButton
ID_DefaultDeactiveTabSampleLabel
ID_ReadingDeactiveTabSampleLabel
ID_BrokenDeactiveTabSampleLabel
ID_CannotPostDeactiveTabSampleLabel
ID_UpdateDeactiveTabSampleLabel
ID_PartialContentDeactiveTabSampleLabel
ID_ThreadTabDefaultFontColorButton
ID_ThreadTabReadingFontColorButton
ID_ThreadTabBrokenFontColorButton
ID_ThreadTabCannotPostFontColorButton
ID_ThreadTabUpdateFontColorButton
ID_ThreadTabPartialContentFontColorButton
ID_AutoReloadSampleLabel
ID_AutoReloadFontColorButton
ID_TabControlSettingPanel
ID_TabControlSettingPanelOpenTabChoice
ID_TabControlSettingPanelOpenTabFromOtherTabChoice
ID_TabControlSettingPanelCloseThreadViewTabChoice
ID_TabControlSettingPanelCloseThreadTabChoice
ID_AddThreadFavorite : お気に入りに追加(スレッド)
ID_DelThreadFavorite : お気に入りを削除(スレッド)
ID_AddBoardFavorite : お気に入りに追加(板)
ID_DelBoardFavorite : お気に入りを削除(板)
ID_AddAllThreadFavorite : すべてのタブをお気に入りに追加
ID_ResponseWindowSageChk : レス用ウィンドウのsageチェック
ID_ResponseWindowBeChk : レス用ウィンドウのBEチェック
ID_ChangeUserLastAttached : ユーザーが最後に触ったウィジェットを記録
ID_ReloadThreadByName : スレッド名を元にスレッドを更新する
ID_NewBoardAddDialog : 外部板登録ダイアログ
ID_CallNewBoardAddDialog : 外部板登録用ダイアログを呼び出す
ID_OperationPanel : 各種操作設定用画面
ID_KakikomiPanel : 書き込み設定用画面
ID_DoePanel : スレ表示欄の設定画面
ID_OtherSettingPanelOne : その他の設定画面１
ID_ResetBoardListTree : 板一覧ツリーのウィジェットの初期化イベント
ID_Receive_Timeout_Sec : 受信タイムアウト秒
ID_Connection_Timeout_Sec : 接続タイムアウト秒
ID_JaneCloneEnumsEnd
*/
