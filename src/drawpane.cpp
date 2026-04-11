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

#include "drawpane.hpp"

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
// some useful events
/*
  EVT_MOTION(BasicDrawPane::mouseMoved)
  EVT_LEFT_DOWN(BasicDrawPane::mouseDown)
  EVT_LEFT_UP(BasicDrawPane::mouseReleased)
  EVT_RIGHT_DOWN(BasicDrawPane::rightClick)
  EVT_LEAVE_WINDOW(BasicDrawPane::mouseLeftWindow)
  EVT_KEY_DOWN(BasicDrawPane::keyPressed)
  EVT_KEY_UP(BasicDrawPane::keyReleased)
  EVT_MOUSEWHEEL(BasicDrawPane::mouseWheelMoved)
*/

// catch paint events
EVT_PAINT(BasicDrawPane::PaintEvent)

END_EVENT_TABLE()

// some useful events
/*
  void BasicDrawPane::mouseMoved(wxMouseEvent& event) {}
  void BasicDrawPane::mouseDown(wxMouseEvent& event) {}
  void BasicDrawPane::mouseWheelMoved(wxMouseEvent& event) {}
  void BasicDrawPane::mouseReleased(wxMouseEvent& event) {}
  void BasicDrawPane::rightClick(wxMouseEvent& event) {}
  void BasicDrawPane::mouseLeftWindow(wxMouseEvent& event) {}
  void BasicDrawPane::keyPressed(wxKeyEvent& event) {}
  void BasicDrawPane::keyReleased(wxKeyEvent& event) {}
*/

BasicDrawPane::BasicDrawPane(wxWindow* parent, wxWindowID id, const wxString& title) :
wxPanel(parent)
{
    // 内部テキスト
    m_text = title;
    // ID
    this->SetId(id);
}

/*
 * Called by the system of by wxWidgets when the panel needs
 * to be redrawn. You can also trigger this call by
 * calling Refresh()/Update().
 */
void BasicDrawPane::PaintEvent(wxPaintEvent & evt)
{
    wxPaintDC dc(this);
    this->Render(dc);
}
/*
 * Alternatively, you can use a clientDC to paint on the panel
 * at any time. Using this generally does not free you from
 * catching paint events, since it is possible that e.g. the window
 * manager throws away your drawing when the window comes to the
 * background, and expects you will redraw it when the window comes
 * back (by sending a paint event).
 *
 * In most cases, this will not be needed at all; simply handling
 * paint events and calling Refresh() when a refresh is needed
 * will do the job.
 */
void BasicDrawPane::PaintNow()
{
    wxClientDC dc(this);
    this->Render(dc);
}
/*
 * Here we do the actual rendering. I put it in a separate
 * method so that it can work no matter what type of DC
 * (e.g. wxPaintDC or wxClientDC) is used.
 */
void BasicDrawPane::Render(wxDC&  dc)
{

    int width, height;
    this->GetSize(&width, &height);

    if ( m_bgColor.IsOk() )
        {
            dc.SetBrush(wxBrush(m_bgColor));
            dc.DrawRectangle(0, 0, width, height);
        }

    if ( m_textForeGround.IsOk() )
        {
            dc.SetTextForeground( m_textForeGround );
        }

    if ( !m_text.IsEmpty() )
        {
            dc.SetBackgroundMode(wxTRANSPARENT);
            dc.SetFont( m_font );

            /*
             * ちょうど中央表示できるよう調整
             */
            const int cHeight = dc.GetCharHeight();
            const int cWidth  = dc.GetCharWidth();
            const int textLen = m_text.Len();
            const int textHalfSize = textLen * cWidth / 2;
            dc.DrawText( m_text, width / 2 - textHalfSize, height / 2 - cHeight / 2 );
        }
}
