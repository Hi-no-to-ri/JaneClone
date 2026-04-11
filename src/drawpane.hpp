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

#ifndef DRAWPANE_HPP_
#define DRAWPANE_HPP_

#include <wx/wx.h>
#include <wx/sizer.h>
#include <wx/brush.h>

/**
 * wxPanel上にGUIを「描画」するためのクラス
 * 文字通り描画するため自由度が高い
 *
 * Reference: http://wiki.wxwidgets.org/Drawing_on_a_panel_with_a_DC
 */
class BasicDrawPane : public wxPanel
{

public:
    BasicDrawPane(wxWindow* parent, wxWindowID id, const wxString& title);

    void PaintEvent(wxPaintEvent & evt);
    void PaintNow();
    void Render(wxDC& dc);

    void SetInnerFont(const wxFont& font)
    {
        m_font = font;
    };

    void SetInnerText(const wxString& text)
    {
        m_text = text;
    };

    void SetInnerBGColor(const wxColour& color)
    {
        m_bgColor = color;
    };

    void SetInnerTextForeGroundColor(const wxColour& color)
    {
        m_textForeGround = color;
    };

    // some useful events
    /*
      void mouseMoved(wxMouseEvent& event);
      void mouseDown(wxMouseEvent& event);
      void mouseWheelMoved(wxMouseEvent& event);
      void mouseReleased(wxMouseEvent& event);
      void rightClick(wxMouseEvent& event);
      void mouseLeftWindow(wxMouseEvent& event);
      void keyPressed(wxKeyEvent& event);
      void keyReleased(wxKeyEvent& event);
    */

private:

    // 内部で保存するフォント
    wxFont   m_font;
    // 内部で保存するテキスト
    wxString m_text;
    // 内部で保存する背景色
    wxColour m_bgColor;
    // 内部で保存するテキストの色
    wxColour m_textForeGround;

    DECLARE_EVENT_TABLE()
};

#endif /* DRAWPANE_HPP_ */
