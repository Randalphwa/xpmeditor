/***************************************************************
 * Plugin:    XPMEditor for Code::Blocks
 * Name:      XPMToolPanel.cpp
 * Purpose:   A panel containing all the drawing tools - code
 * Author:    Seb (seb_seb0@lycos.com)
 * Created:   2010-05-19
 * Copyright: Seb ()
 * License:   GPL 3.0
 **************************************************************/

#include "XPMToolPanel.h"

#include <wx/dcclient.h>
#include <wx/dcmemory.h>
#include <wx/textctrl.h>
#include "wxResizeCtrl.h"

//button icons
#include "xpm/brush.xpm"
#include "xpm/curve.xpm"
#include "xpm/ellipse.xpm"
#include "xpm/eraser.xpm"
#include "xpm/fill.xpm"
#include "xpm/lasso.xpm"
#include "xpm/line.xpm"
#include "xpm/pen.xpm"
#include "xpm/pipette.xpm"
#include "xpm/polygon.xpm"
#include "xpm/rectangle.xpm"
#include "xpm/roundedrect.xpm"
#include "xpm/selection.xpm"
#include "xpm/text.xpm"
#include "xpm/hotspot.xpm"

//cursors
#include "xpm/cross_cursor.xpm"
#include "xpm/pipette_cursor.xpm"
#include "xpm/fill_cursor.xpm"
#include "xpm/pen_cursor.xpm"

//additional tools icons
#include "xpm/circle.xpm"
#include "xpm/square.xpm"
#include "xpm/left_hair.xpm"
#include "xpm/right_hair.xpm"

//(*InternalHeaders(XPMToolPanel)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(XPMToolPanel)
const long XPMToolPanel::ID_SELECT_BUTN = wxNewId();
const long XPMToolPanel::ID_LASSO_BTN = wxNewId();
const long XPMToolPanel::ID_HOTSPOT_BTN = wxNewId();
const long XPMToolPanel::ID_PEN_BTN = wxNewId();
const long XPMToolPanel::ID_BRUSH_BTN = wxNewId();
const long XPMToolPanel::ID_PIPETTE_BTN = wxNewId();
const long XPMToolPanel::ID_FILL_BTN = wxNewId();
const long XPMToolPanel::ID_LINE_BTN = wxNewId();
const long XPMToolPanel::ID_CURVE_BTN = wxNewId();
const long XPMToolPanel::ID_ERASER_BTN = wxNewId();
const long XPMToolPanel::ID_TEXT_BTN = wxNewId();
const long XPMToolPanel::ID_RECTANGLE_BTN = wxNewId();
const long XPMToolPanel::ID_POLYGON_BTN = wxNewId();
const long XPMToolPanel::ID_ELLIPSE_BTN = wxNewId();
const long XPMToolPanel::ID_ROUNDEDRECT_BTN = wxNewId();
const long XPMToolPanel::ID_SQUARE_BRUSH = wxNewId();
const long XPMToolPanel::ID_CIRCLE_BRUSH = wxNewId();
const long XPMToolPanel::ID_LRHAIR_BRUSH = wxNewId();
const long XPMToolPanel::ID_LHAIR_BRUSH = wxNewId();
const long XPMToolPanel::ID_CUSTOM2 = wxNewId();
const long XPMToolPanel::ID_FONT_BUTTON = wxNewId();
const long XPMToolPanel::ID_BKMODE_TOGGLEBUTTON = wxNewId();
const long XPMToolPanel::ID_STATICTEXT8 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON1 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON9 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON8 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON7 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON6 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON5 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON4 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON3 = wxNewId();
const long XPMToolPanel::ID_RADIOBUTTON2 = wxNewId();
const long XPMToolPanel::ID_PANEL2 = wxNewId();
const long XPMToolPanel::ID_STATICTEXT9 = wxNewId();
const long XPMToolPanel::ID_SPINCTRL6 = wxNewId();
const long XPMToolPanel::ID_STATICTEXT5 = wxNewId();
const long XPMToolPanel::ID_SPINCTRL3 = wxNewId();
const long XPMToolPanel::ID_STATICTEXT7 = wxNewId();
const long XPMToolPanel::ID_SPINCTRL5 = wxNewId();
const long XPMToolPanel::ID_STATICTEXT6 = wxNewId();
const long XPMToolPanel::ID_SPINCTRL4 = wxNewId();
const long XPMToolPanel::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(XPMToolPanel,wxPanel)
	//(*EventTable(XPMToolPanel)
	//*)
END_EVENT_TABLE()

XPMToolPanel::XPMToolPanel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, wxColour cHotSpotColour)
{
	//(*Initialize(XPMToolPanel)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer14;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	ToolPanel = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	ToolPanelSizer = new wxBoxSizer(wxVERTICAL);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	SelectButton = new wxCustomButton(ToolPanel,ID_SELECT_BUTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_SELECT_BUTN"));
	SelectButton->SetBitmapDisabled(SelectButton->CreateBitmapDisabled(SelectButton->GetBitmapLabel()));
	SelectButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer6->Add(SelectButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	LassoButton = new wxCustomButton(ToolPanel,ID_LASSO_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_LASSO_BTN"));
	LassoButton->SetBitmapDisabled(LassoButton->CreateBitmapDisabled(LassoButton->GetBitmapLabel()));
	LassoButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer6->Add(LassoButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	HotSpotButton = new wxCustomButton(ToolPanel,ID_HOTSPOT_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_HOTSPOT_BTN"));
	HotSpotButton->SetBitmapDisabled(HotSpotButton->CreateBitmapDisabled(HotSpotButton->GetBitmapLabel()));
	HotSpotButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer6->Add(HotSpotButton, 0, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 2);
	ToolPanelSizer->Add(BoxSizer6, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	PenButton = new wxCustomButton(ToolPanel,ID_PEN_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_PEN_BTN"));
	PenButton->SetBitmapDisabled(PenButton->CreateBitmapDisabled(PenButton->GetBitmapLabel()));
	PenButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer5->Add(PenButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	BrushButton = new wxCustomButton(ToolPanel,ID_BRUSH_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_BRUSH_BTN"));
	BrushButton->SetBitmapDisabled(BrushButton->CreateBitmapDisabled(BrushButton->GetBitmapLabel()));
	BrushButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer5->Add(BrushButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	PipetteButton = new wxCustomButton(ToolPanel,ID_PIPETTE_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_PIPETTE_BTN"));
	PipetteButton->SetBitmapDisabled(PipetteButton->CreateBitmapDisabled(PipetteButton->GetBitmapLabel()));
	PipetteButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer5->Add(PipetteButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	FillButton = new wxCustomButton(ToolPanel,ID_FILL_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_FILL_BTN"));
	FillButton->SetBitmapDisabled(FillButton->CreateBitmapDisabled(FillButton->GetBitmapLabel()));
	FillButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer5->Add(FillButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	ToolPanelSizer->Add(BoxSizer5, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	LineButton = new wxCustomButton(ToolPanel,ID_LINE_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_LINE_BTN"));
	LineButton->SetBitmapDisabled(LineButton->CreateBitmapDisabled(LineButton->GetBitmapLabel()));
	LineButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer7->Add(LineButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	CurveButton = new wxCustomButton(ToolPanel,ID_CURVE_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_CURVE_BTN"));
	CurveButton->SetBitmapDisabled(CurveButton->CreateBitmapDisabled(CurveButton->GetBitmapLabel()));
	CurveButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer7->Add(CurveButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	EraserButton = new wxCustomButton(ToolPanel,ID_ERASER_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_ERASER_BTN"));
	EraserButton->SetBitmapDisabled(EraserButton->CreateBitmapDisabled(EraserButton->GetBitmapLabel()));
	EraserButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer7->Add(EraserButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	TextButton = new wxCustomButton(ToolPanel,ID_TEXT_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_TEXT_BTN"));
	TextButton->SetBitmapDisabled(TextButton->CreateBitmapDisabled(TextButton->GetBitmapLabel()));
	TextButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer7->Add(TextButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	ToolPanelSizer->Add(BoxSizer7, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	RectangleButton = new wxCustomButton(ToolPanel,ID_RECTANGLE_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_RECTANGLE_BTN"));
	RectangleButton->SetBitmapDisabled(RectangleButton->CreateBitmapDisabled(RectangleButton->GetBitmapLabel()));
	RectangleButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer10->Add(RectangleButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	PolygonButton = new wxCustomButton(ToolPanel,ID_POLYGON_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_POLYGON_BTN"));
	PolygonButton->SetBitmapDisabled(PolygonButton->CreateBitmapDisabled(PolygonButton->GetBitmapLabel()));
	PolygonButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer10->Add(PolygonButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	EllipseButton = new wxCustomButton(ToolPanel,ID_ELLIPSE_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_ELLIPSE_BTN"));
	EllipseButton->SetBitmapDisabled(EllipseButton->CreateBitmapDisabled(EllipseButton->GetBitmapLabel()));
	EllipseButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer10->Add(EllipseButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 2);
	RRectButton = new wxCustomButton(ToolPanel,ID_ROUNDEDRECT_BTN,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_ADD_BOOKMARK")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_ROUNDEDRECT_BTN"));
	RRectButton->SetBitmapDisabled(RRectButton->CreateBitmapDisabled(RRectButton->GetBitmapLabel()));
	RRectButton->SetBitmapMargin(wxSize(2,2));
	BoxSizer10->Add(RRectButton, 0, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 2);
	ToolPanelSizer->Add(BoxSizer10, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	ToolPanelSizer->Add(-1,-1,0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	SquareBrushButton = new wxCustomButton(ToolPanel,ID_SQUARE_BRUSH,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_SQUARE_BRUSH"));
	SquareBrushButton->SetBitmapDisabled(SquareBrushButton->CreateBitmapDisabled(SquareBrushButton->GetBitmapLabel()));
	SquareBrushButton->SetBitmapMargin(wxSize(5,5));
	BoxSizer2->Add(SquareBrushButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 2);
	CircleBrushButton = new wxCustomButton(ToolPanel,ID_CIRCLE_BRUSH,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_CIRCLE_BRUSH"));
	CircleBrushButton->SetBitmapDisabled(CircleBrushButton->CreateBitmapDisabled(CircleBrushButton->GetBitmapLabel()));
	CircleBrushButton->SetBitmapMargin(wxSize(5,5));
	BoxSizer2->Add(CircleBrushButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 2);
	RHairBrushButton = new wxCustomButton(ToolPanel,ID_LRHAIR_BRUSH,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_LRHAIR_BRUSH"));
	RHairBrushButton->SetBitmapDisabled(RHairBrushButton->CreateBitmapDisabled(RHairBrushButton->GetBitmapLabel()));
	RHairBrushButton->SetBitmapMargin(wxSize(5,5));
	BoxSizer2->Add(RHairBrushButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 2);
	LHairBrushButton = new wxCustomButton(ToolPanel,ID_LHAIR_BRUSH,wxEmptyString,wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_BUTTON),wxDefaultPosition,wxDefaultSize,wxCUSTBUT_TOGGLE|wxCUSTBUT_BOTTOM,wxDefaultValidator,_T("ID_LHAIR_BRUSH"));
	LHairBrushButton->SetBitmapDisabled(LHairBrushButton->CreateBitmapDisabled(LHairBrushButton->GetBitmapLabel()));
	LHairBrushButton->SetBitmapMargin(wxSize(5,5));
	BoxSizer2->Add(LHairBrushButton, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 2);
	ToolPanelSizer->Add(BoxSizer2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	HotSpotColourPicker = new wxColourPickerCtrl(ToolPanel,ID_CUSTOM2,cHotSpotColour,wxDefaultPosition,wxDefaultSize,wxCLRP_USE_TEXTCTRL,wxDefaultValidator,_T("ID_CUSTOM2"));
	ToolPanelSizer->Add(HotSpotColourPicker, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	FontButton = new wxButton(ToolPanel, ID_FONT_BUTTON, _("FONT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_FONT_BUTTON"));
	ToolPanelSizer->Add(FontButton, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BackgroundButton = new wxToggleButton(ToolPanel, ID_BKMODE_TOGGLEBUTTON, _("OPAQUE"), wxDefaultPosition, wxSize(90,23), 0, wxDefaultValidator, _T("ID_BKMODE_TOGGLEBUTTON"));
	ToolPanelSizer->Add(BackgroundButton, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	AlignmentPanel = new wxPanel(ToolPanel, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer14 = new wxBoxSizer(wxVERTICAL);
	StaticText7 = new wxStaticText(AlignmentPanel, ID_STATICTEXT8, _("Alignment"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer14->Add(StaticText7, 0, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	TopLeft = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
	TopLeft->SetValue(true);
	BoxSizer4->Add(TopLeft, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 1);
	TopCenter = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON9, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON9"));
	BoxSizer4->Add(TopCenter, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_TOP, 1);
	TopRight = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON8, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON8"));
	BoxSizer4->Add(TopRight, 0, wxTOP|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_TOP, 1);
	BoxSizer14->Add(BoxSizer4, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	CenterLeft = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON7, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON7"));
	BoxSizer9->Add(CenterLeft, 0, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 1);
	CenterCenter = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
	BoxSizer9->Add(CenterCenter, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	CenterRight = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
	BoxSizer9->Add(CenterRight, 0, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer14->Add(BoxSizer9, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	BottomLeft = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
	BoxSizer11->Add(BottomLeft, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_BOTTOM, 1);
	BottomCenter = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON3, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
	BoxSizer11->Add(BottomCenter, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 1);
	BottomRight = new wxRadioButton(AlignmentPanel, ID_RADIOBUTTON2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
	BoxSizer11->Add(BottomRight, 0, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_BOTTOM, 1);
	BoxSizer14->Add(BoxSizer11, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 0);
	AlignmentPanel->SetSizer(BoxSizer14);
	BoxSizer14->Fit(AlignmentPanel);
	BoxSizer14->SetSizeHints(AlignmentPanel);
	ToolPanelSizer->Add(AlignmentPanel, 0, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	AngleSizer = new wxBoxSizer(wxVERTICAL);
	StaticText8 = new wxStaticText(ToolPanel, ID_STATICTEXT9, _("Angle (deg):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	AngleSizer->Add(StaticText8, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	SpinAngle = new wxSpinCtrl(ToolPanel, ID_SPINCTRL6, _T("0"), wxDefaultPosition, wxSize(72,21), 0, 0, 360, 0, _T("ID_SPINCTRL6"));
	SpinAngle->SetValue(_T("0"));
	AngleSizer->Add(SpinAngle, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
	ToolPanelSizer->Add(AngleSizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 0);
	StaticText4 = new wxStaticText(ToolPanel, ID_STATICTEXT5, _("Size:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	ToolPanelSizer->Add(StaticText4, 0, wxTOP|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	SpinCtrl1 = new wxSpinCtrl(ToolPanel, ID_SPINCTRL3, _T("4"), wxDefaultPosition, wxSize(83,21), 0, 2, 16, 4, _T("ID_SPINCTRL3"));
	SpinCtrl1->SetValue(_T("4"));
	ToolPanelSizer->Add(SpinCtrl1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	StaticText6 = new wxStaticText(ToolPanel, ID_STATICTEXT7, _("Radius:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	ToolPanelSizer->Add(StaticText6, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	SpinCtrl3 = new wxSpinCtrl(ToolPanel, ID_SPINCTRL5, _T("1"), wxDefaultPosition, wxSize(20,21), 0, 1, 1000, 1, _T("ID_SPINCTRL5"));
	SpinCtrl3->SetValue(_T("1"));
	ToolPanelSizer->Add(SpinCtrl3, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	StaticText5 = new wxStaticText(ToolPanel, ID_STATICTEXT6, _("Thickness:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	ToolPanelSizer->Add(StaticText5, 0, wxALL|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	SpinCtrl2 = new wxSpinCtrl(ToolPanel, ID_SPINCTRL4, _T("1"), wxDefaultPosition, wxSize(20,21), 0, 1, 16, 1, _T("ID_SPINCTRL4"));
	SpinCtrl2->SetValue(_T("1"));
	ToolPanelSizer->Add(SpinCtrl2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	ToolPanelSizer->Add(62,-1,1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_BOTTOM, 5);
	ToolPanel->SetSizer(ToolPanelSizer);
	ToolPanelSizer->Fit(ToolPanel);
	ToolPanelSizer->SetSizeHints(ToolPanel);
	BoxSizer1->Add(ToolPanel, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	
	Connect(ID_SELECT_BUTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnSelectButtonToggle);
	Connect(ID_LASSO_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnLassoButtonToggle);
	Connect(ID_HOTSPOT_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnHotSpotButtonToggle);
	Connect(ID_PEN_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnPenButtonToggle);
	Connect(ID_BRUSH_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnBrushButtonToggle);
	Connect(ID_PIPETTE_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnPipetteButtonToggle);
	Connect(ID_FILL_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnFillButtonToggle);
	Connect(ID_LINE_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnLineButtonToggle);
	Connect(ID_CURVE_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnCurveButtonToggle);
	Connect(ID_ERASER_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnEraserButtonToggle);
	Connect(ID_TEXT_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnTextButtonToggle);
	Connect(ID_RECTANGLE_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnRectangleButtonToggle);
	Connect(ID_POLYGON_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnPolygonButtonToggle);
	Connect(ID_ELLIPSE_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnEllipseButtonToggle);
	Connect(ID_ROUNDEDRECT_BTN,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnRRectButtonToggle);
	Connect(ID_SQUARE_BRUSH,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnSquareBrushButtonToggle);
	Connect(ID_CIRCLE_BRUSH,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnCircleBrushButtonToggle);
	Connect(ID_LRHAIR_BRUSH,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnRHairBrushButtonToggle);
	Connect(ID_LHAIR_BRUSH,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnLHairBrushButtonToggle);
	Connect(ID_FONT_BUTTON,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnFontButtonClick);
	Connect(ID_BKMODE_TOGGLEBUTTON,wxEVT_COMMAND_TOGGLEBUTTON_CLICKED,(wxObjectEventFunction)&XPMToolPanel::OnBackgroundButtonToggle);
	Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnTopLeftSelect);
	Connect(ID_RADIOBUTTON9,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnTopCenterSelect);
	Connect(ID_RADIOBUTTON8,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnTopRightSelect);
	Connect(ID_RADIOBUTTON7,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnCenterLeftSelect);
	Connect(ID_RADIOBUTTON6,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnCenterCenterSelect);
	Connect(ID_RADIOBUTTON5,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnCenterRightSelect);
	Connect(ID_RADIOBUTTON4,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnBottomLeftSelect);
	Connect(ID_RADIOBUTTON3,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnBottomCenterSelect);
	Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&XPMToolPanel::OnBottomRightSelect);
	Connect(ID_SPINCTRL6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&XPMToolPanel::OnSpinAngleChange);
	Connect(ID_SPINCTRL3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&XPMToolPanel::OnSpinSizeChanged);
	Connect(ID_SPINCTRL5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&XPMToolPanel::OnSpinRadiusChanged);
	Connect(ID_SPINCTRL4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&XPMToolPanel::OnSpinThicknessChanged);
	//*)

	m_parent = NULL;

	//set the bitmaps on the button
	wxBitmap bBrush(brush_xpm);
	BrushButton->SetLabel(bBrush);

	wxBitmap bCurve(CURVE_xpm);
	CurveButton->SetLabel(bCurve);

	wxBitmap bEllipse(ELLIPSE_xpm);
	EllipseButton->SetLabel(bEllipse);

	wxBitmap bEraser(ERASER_xpm);
	EraserButton->SetLabel(bEraser);

	wxBitmap bFill(FILL_xpm);
	FillButton->SetLabel(bFill);

	wxBitmap bLasso(LASSO_xpm);
	LassoButton->SetLabel(bLasso);

	wxBitmap bLine(LINE_xpm);
	LineButton->SetLabel(bLine);

	wxBitmap bPen(PEN_xpm);
	PenButton->SetLabel(bPen);

	wxBitmap bPipette(PIPETTE_xpm);
	PipetteButton->SetLabel(bPipette);

	wxBitmap bPolygon(POLYGON_xpm);
	PolygonButton->SetLabel(bPolygon);

	wxBitmap bRectangle(RECT_xpm);
	RectangleButton->SetLabel(bRectangle);

	wxBitmap bRoundedRectangle(RRECT_xpm);
	RRectButton->SetLabel(bRoundedRectangle);

	wxBitmap bSelection(SEL_xpm);
	SelectButton->SetLabel(bSelection);

	wxBitmap bText(TEXT_xpm);
    TextButton->SetLabel(bText);

    wxBitmap bHotSpot(hotspot_xpm);
    HotSpotButton->SetLabel(bHotSpot);

    SquareBrushButton->Hide();
    SquareBrushButton->SetLabel(square_xpm);
    CircleBrushButton->Hide();
    CircleBrushButton->SetLabel(circle_xpm);
    LHairBrushButton->Hide();
    LHairBrushButton->SetLabel(left_hair_xpm);
    RHairBrushButton->Hide();
    RHairBrushButton->SetLabel(right_hair_xpm);

    StaticText4->Hide();
    SpinCtrl1->Hide();
    StaticText5->Hide();
    SpinCtrl2->Hide();
    StaticText6->Hide();
    SpinCtrl3->Hide();
    FontButton->Hide();
    BackgroundButton->Hide();
    AlignmentPanel->Hide();
    StaticText8->Hide();
    SpinAngle->Hide();
    HotSpotColourPicker->Hide();
    ToolPanelSizer->Layout();
    ToolPanelSizer->FitInside(ToolPanel);


    //tools IDs
	tools[XPM_ID_SELECT_TOOL] = SelectButton;
	tools[XPM_ID_LASSO_TOOL] = LassoButton;
	tools[XPM_ID_PEN_TOOL] = PenButton;
	tools[XPM_ID_BRUSH_TOOL] = BrushButton;
    tools[XPM_ID_PIPETTE_TOOL] = PipetteButton;
    tools[XPM_ID_FILL_TOOL] = FillButton;
    tools[XPM_ID_CURVE_TOOL] = CurveButton;
    tools[XPM_ID_LINE_TOOL] = LineButton;
    tools[XPM_ID_ERASER_TOOL] = EraserButton;
    tools[XPM_ID_TEXT_TOOL] = TextButton;
    tools[XPM_ID_RECTANGLE_TOOL]= RectangleButton;
    tools[XPM_ID_POLYGON_TOOL]= PolygonButton;
    tools[XPM_ID_ELLIPSE_TOOL]= EllipseButton;
    tools[XPM_ID_ROUNDEDRECT_TOOL] = RRectButton;
    tools[XPM_ID_HOTSPOT_TOOL] = HotSpotButton;

    //tools cursors
    wxImage ImgCrossCursor(cross_cursor_xpm);
    ImgCrossCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, 16);
    ImgCrossCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, 16);
    wxImage ImgPenCursor(pen_cursor_xpm);
    ImgPenCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, 14);
    ImgPenCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, 25);
    wxImage ImgPipetteCursor(pipette_cursor_xpm);
    ImgPipetteCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, 8);
    ImgPipetteCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, 23);
    wxImage ImgFillCursor(fill_cursor_xpm);
    ImgFillCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, 8);
    ImgFillCursor.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, 22);


    ToolCursor[XPM_ID_SELECT_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_LASSO_TOOL] = wxCursor(ImgCrossCursor);
	ToolCursor[XPM_ID_PEN_TOOL] = wxCursor(ImgPenCursor);
	ToolCursor[XPM_ID_BRUSH_TOOL] = wxCursor(wxCURSOR_PAINT_BRUSH);
    ToolCursor[XPM_ID_PIPETTE_TOOL] = wxCursor(ImgPipetteCursor);
    ToolCursor[XPM_ID_FILL_TOOL] = wxCursor(ImgFillCursor);
    ToolCursor[XPM_ID_CURVE_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_LINE_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_ERASER_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_TEXT_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_RECTANGLE_TOOL]= wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_POLYGON_TOOL]= wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_ELLIPSE_TOOL]= wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_ROUNDEDRECT_TOOL] = wxCursor(ImgCrossCursor);
    ToolCursor[XPM_ID_HOTSPOT_TOOL] = wxCursor(ImgCrossCursor);

    iToolUsed = -1;

    //colour picker control event
	HotSpotColourPicker->Connect(wxEVT_COMMAND_COLOURPICKER_CHANGED,(wxObjectEventFunction)&XPMEditorPanel::OnHotSpotColourPickerColourChanged,0,this);
}

XPMToolPanel::~XPMToolPanel()
{
	//(*Destroy(XPMToolPanel)
	//*)
}


/** Set the parent panel
  * \param [in] a pointer to the new parent
  */
void XPMToolPanel::SetParentPanel(XPMEditorPanel *p)
{
    m_parent = p;
}

//---- TOOLS ID & CURSORS ----------------------//
/** Return the ID of the tool currently in use
  * \param the tool ID, -1 if no tool are currently selected
  */
int XPMToolPanel::GetToolID(void)
{
    return(iToolUsed);
}

/** Set the ID of the tool currently in use
  * Do not modify the state of the buttons
  * \param the tool ID, -1 if no tool are currently selected
  */
void XPMToolPanel::SetToolID(int iTool)
{
    iToolUsed = iTool;
}

/** init tool data for a first use
  */
void XPMToolPanel::InitToolData(void)
{
    if (m_parent)
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);

        tdata.x1 = -1;
        tdata.y1 = -1;
        tdata.x2 = -1;
        tdata.y2 = -1;
        tdata.iNbClicks = 0;
        tdata.iNbPoints = 0;
        //tdata.font = GetFont();
        tdata.sText = _("");

        int i;
        for(i=0;i < XPM_MAXPOINTS; i++)
        {
            tdata.pts[i].x = -1;
            tdata.pts[i].y = -1;
        }

        switch(GetToolID())
        {
            case XPM_ID_ERASER_TOOL:
            case XPM_ID_BRUSH_TOOL : tdata.iSize2 = SpinCtrl1->GetValue();
                                     if (tdata.iSize2 < 2) tdata.iSize2 = 2;
                                     //init one kind of brush
                                     if (!(   (SquareBrushButton->GetValue()) || (CircleBrushButton->GetValue())
                                           || (LHairBrushButton->GetValue()) || (RHairBrushButton->GetValue())
                                          )
                                         )
                                     {
                                        CircleBrushButton->SetValue(false);
                                        LHairBrushButton->SetValue(false);
                                        RHairBrushButton->SetValue(false);
                                        tdata.iStyle = XPM_BRUSH_STYLE_SQUARE;
                                        SquareBrushButton->SetValue(true);
                                     }
                                     break;

            case XPM_ID_LINE_TOOL:
            case XPM_ID_CURVE_TOOL:
            case XPM_ID_RECTANGLE_TOOL:
            case XPM_ID_POLYGON_TOOL:
            case XPM_ID_ELLIPSE_TOOL: tdata.iSize = SpinCtrl2->GetValue();
                                      if (tdata.iSize < 1) tdata.iSize = 1;
                                      break;

            case XPM_ID_ROUNDEDRECT_TOOL: tdata.iSize = SpinCtrl2->GetValue();
                                          if (tdata.iSize < 1) tdata.iSize = 1;

                                          tdata.iRadius = SpinCtrl3->GetValue();
                                          if (tdata.iRadius < 0) tdata.iRadius = 0;
                                          break;

            case XPM_ID_TEXT_TOOL: if (BackgroundButton->GetValue())
                                   {
                                       tdata.iStyle = wxTRANSPARENT;
                                   }
                                   else
                                   {
                                       tdata.iStyle = wxSOLID;
                                   }
                                   if (TopLeft->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_LEFT;
                                       tdata.iVertAlign = wxALIGN_TOP;
                                   }
                                   if (TopCenter->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_CENTER;
                                       tdata.iVertAlign = wxALIGN_TOP;
                                   }
                                   if (TopRight->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_RIGHT;
                                       tdata.iVertAlign = wxALIGN_TOP;
                                   }
                                   if (CenterLeft->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_LEFT;
                                       tdata.iVertAlign = wxALIGN_CENTER;
                                   }
                                   if (CenterCenter->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_CENTER;
                                       tdata.iVertAlign = wxALIGN_CENTER;
                                   }
                                   if (CenterRight->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_RIGHT;
                                       tdata.iVertAlign = wxALIGN_CENTER;
                                   }
                                   if (BottomLeft->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_LEFT;
                                       tdata.iVertAlign = wxALIGN_BOTTOM;
                                   }
                                   if (BottomCenter->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_CENTER;
                                       tdata.iVertAlign = wxALIGN_BOTTOM;
                                   }
                                   if (BottomRight->GetValue())
                                   {
                                       tdata.iHorizAlign = wxALIGN_RIGHT;
                                       tdata.iVertAlign = wxALIGN_BOTTOM;
                                   }

                                   tdata.angle = SpinAngle->GetValue();
                                   break;

            default: break;
        }

        m_parent->SetToolData(&tdata);
        SetToolCursor();
    }
}


/** Set the correct cursor, according to the currently selected tool & option
  */
void XPMToolPanel::SetToolCursor(void)
{
    //Set the correct cursor, according to the currently selected tool & option
    if (m_parent)
    {
        int iTool;
        iTool = GetToolID();

        if ((iTool < 0) || (iTool >= XPM_NUMBER_TOOLS))
        {
            m_parent->SetToolCursor(wxCURSOR_ARROW);
        }
        else if (iTool == XPM_ID_BRUSH_TOOL)
        {
            //create the correct cursor
            //1 - create the bitmap
            int iSize, iSizeMin;
            double dScale2, dScale;
            ToolData tdata;

            dScale = m_parent->GetScaleFactor();
            m_parent->GetToolData(&tdata);

            if (dScale < 1) dScale2 = 1; else dScale2 = dScale;
            if (tdata.iSize < 2) tdata.iSize = 2;
            iSize = tdata.iSize * dScale2;
            if (tdata.iStyle == XPM_BRUSH_STYLE_SQUARE) iSize = iSize + 2 * dScale2;
            if ((tdata.iStyle == XPM_BRUSH_STYLE_CIRCLE) && (tdata.iSize * dScale2 <= 4)) iSize = 5;
            if (iSize < 8) iSizeMin = 8; else iSizeMin = iSize;
            wxBitmap bm(iSizeMin, iSizeMin);

            //2 - draw on the bitmap
            wxMemoryDC mem_dc;
            mem_dc.SelectObject(bm);
            mem_dc.SetBrush(*wxRED_BRUSH);
            mem_dc.SetPen(*wxRED_PEN);

            switch (tdata.iStyle)
            {
                case XPM_BRUSH_STYLE_CIRCLE   :
                    mem_dc.DrawRectangle(0,0,iSizeMin, iSizeMin);
                    mem_dc.SetBrush(*wxBLACK_BRUSH);
                    mem_dc.SetPen(*wxWHITE_PEN);
                    mem_dc.DrawCircle(iSizeMin/2, iSizeMin/2, iSizeMin/2);
                    break;

                case XPM_BRUSH_STYLE_LEFTHAIR :
                    mem_dc.DrawRectangle(0,0,iSizeMin, iSizeMin);
                    mem_dc.SetBrush(*wxBLACK_BRUSH);
                    mem_dc.SetPen(*wxBLACK_PEN);
                    mem_dc.DrawLine(0,iSizeMin-1, iSizeMin-1, 0);
                    break;

                case XPM_BRUSH_STYLE_RIGHTHAIR:
                    mem_dc.DrawRectangle(0,0,iSizeMin, iSizeMin);
                    mem_dc.SetBrush(*wxBLACK_BRUSH);
                    mem_dc.SetPen(*wxBLACK_PEN);
                    mem_dc.DrawLine(0,0, iSizeMin-1, iSizeMin-1);
                    break;

                case XPM_BRUSH_STYLE_SQUARE   :
                default:
                    mem_dc.DrawRectangle(0,0,iSizeMin+2, iSizeMin+2);
                    mem_dc.SetBrush(*wxBLACK_BRUSH);
                    mem_dc.SetPen(*wxWHITE_PEN);
                    mem_dc.DrawRectangle(1,1,iSizeMin, iSizeMin);
                    break;
            }
            mem_dc.SetPen(*wxRED_PEN);
            mem_dc.DrawPoint(iSizeMin / 2, iSizeMin / 2);
            mem_dc.SelectObject(wxNullBitmap);

            //3 - convert the wxBitmap to a wxImage, and set the HotSpot
            wxImage img;
            img = bm.ConvertToImage();
            img.SetMaskColour(255,0,0);
            img.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, iSizeMin / 2);
            img.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, iSizeMin / 2);

            //4 - create and set the cursor
            wxCursor cursor(img);
            m_parent->SetToolCursor(cursor);
            m_parent->SetToolData(&tdata);
        }
        else if (iTool == XPM_ID_ERASER_TOOL)
        {
            //create the correct cursor
            //1 - create the bitmap
            int iSize, iSizeMin;
            double dScale, dScale2;
            ToolData tdata;

            dScale = m_parent->GetScaleFactor();
            m_parent->GetToolData(&tdata);

            if (tdata.iSize < 2) tdata.iSize = 2;
            if (dScale < 1) dScale2 = 1; else dScale2 = dScale;
            iSize = (tdata.iSize + 2) * dScale2;
            if (iSize < 8) iSizeMin = 8; else iSizeMin = iSize;
            wxBitmap bm(iSizeMin, iSizeMin);


            //2 - draw on the bitmap
            wxMemoryDC mem_dc;
            mem_dc.SelectObject(bm);
            mem_dc.SetBrush(*wxRED_BRUSH);
            mem_dc.SetPen(*wxRED_PEN);

            mem_dc.DrawRectangle(0,0,iSizeMin, iSizeMin);
            mem_dc.SetBrush(*wxBLACK_BRUSH);
            mem_dc.SetPen(*wxWHITE_PEN);
            mem_dc.DrawRectangle(1,1,iSizeMin-2, iSizeMin-2);
            mem_dc.SetPen(*wxRED_PEN);
            mem_dc.DrawPoint(iSizeMin / 2, iSizeMin / 2);
            mem_dc.SelectObject(wxNullBitmap);

            //3 - convert the wxBitmap to a wxImage, and set the HotSpot
            wxImage img;
            img = bm.ConvertToImage();
            img.SetMaskColour(255,0,0);
            img.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_X, iSizeMin / 2);
            img.SetOption(wxIMAGE_OPTION_CUR_HOTSPOT_Y, iSizeMin / 2);

            //4 - create and set the cursor
            wxCursor cursor(img);
            m_parent->SetToolCursor(cursor);
            m_parent->SetToolData(&tdata);
        }
        else
        {
            m_parent->SetToolCursor(ToolCursor[iTool]);
        }
    }

}

//--- EVENT HANDLERS FOR TOOL BUTTONS ----------//
/** toggle all Tools Buttons OFF, except the iIndex one.
  * \param iIndex: the button to keep ON.
  *                if the button is OFF, it will stay OFF.
  *                if iIndex < 0, then ALL buttons are turned OFF
  * \param bClearSelection: if true, the current selection will be cleared (default).
  */
void XPMToolPanel::ToggleButtons(int iIndex, bool bClearSelection)
{
    //toggle all Tools Buttons OFF, except the iIndex one.
    if (m_parent)
    {
        int i;

        if ((bClearSelection) && (m_parent->HasSelection()))
        {
            m_parent->ClearSelection();
            m_parent->Repaint();
        }

        for(i = 0;i<XPM_NUMBER_TOOLS;i++)
        {
            if ((i != iIndex) &&  (tools[i]))
            {
                if (tools[i]->GetValue()) tools[i]->SetValue(false);
            }
        }
        SetToolID(-1);
        if ((iIndex >=0) && (iIndex < XPM_NUMBER_TOOLS))
        {
            if (tools[iIndex]->GetValue()) SetToolID(iIndex);
        }
        else
        {
            SetToolID(-1);
        }
        InitToolData();
    }

}


/** Hide or Show specific tool controls - like style listbox for Brush tool...
  * \param iIndex: the tool selected
  * \param bChecked: if true, the tool is Activated
  */
void XPMToolPanel::HideControls(int iIndex, bool bChecked)
{
    //hide other controls potentially shown
    if ((iIndex == XPM_ID_BRUSH_TOOL) && (bChecked))
    {
        //show brush tools
        ToolData tdata;
        if (m_parent) m_parent->GetToolData(&tdata);
        tdata.iSize2 = 2;
        SpinCtrl1->SetValue(2);
        if (m_parent) m_parent->SetToolData(&tdata);

        //show tool specific control
        LHairBrushButton->Show(true);
        RHairBrushButton->Show(true);
        CircleBrushButton->Show(true);
        SquareBrushButton->Show(true);
        StaticText4->Show(true);
        SpinCtrl1->Show(true);
        StaticText5->Hide();
        SpinCtrl2->Hide();
        StaticText6->Hide();
        SpinCtrl3->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);

        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Hide();
    }
    else if ((iIndex == XPM_ID_ERASER_TOOL) && (bChecked))
    {
        //show brush tools
        ToolData tdata;
        if (m_parent) m_parent->GetToolData(&tdata);
        tdata.iSize2 = 2;
        SpinCtrl1->SetValue(2);
        if (m_parent) m_parent->SetToolData(&tdata);

        //show tool specific control
        StaticText5->Hide();
        SpinCtrl2->Hide();
        StaticText6->Hide();
        SpinCtrl3->Hide();
        StaticText4->Show(true);
        SpinCtrl1->Show(true);
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Hide();
    }
    else if (    ((iIndex == XPM_ID_LINE_TOOL) && (bChecked))
              || ((iIndex == XPM_ID_CURVE_TOOL) && (bChecked))
              || ((iIndex == XPM_ID_RECTANGLE_TOOL) && (bChecked))
              || ((iIndex == XPM_ID_ELLIPSE_TOOL) && (bChecked))
              || ((iIndex == XPM_ID_POLYGON_TOOL) && (bChecked))
            )
    {
        //show line / curve / polygon / ellipse tools
        ToolData tdata;
        if (m_parent) m_parent->GetToolData(&tdata);
        tdata.iSize = 1;
        SpinCtrl2->SetValue(1);
        if (m_parent) m_parent->SetToolData(&tdata);

        //show tool specific control
        StaticText4->Hide();
        SpinCtrl1->Hide();
        StaticText5->Show(true);
        SpinCtrl2->Show(true);
        StaticText6->Hide();
        SpinCtrl3->Hide();
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Hide();
    }
    else if ((iIndex == XPM_ID_ROUNDEDRECT_TOOL) && (bChecked))
    {
        //show Rounded Rectangle tools
        ToolData tdata;
        if (m_parent) m_parent->GetToolData(&tdata);
        SpinCtrl2->SetValue(1);
        SpinCtrl3->SetValue(2);
        tdata.iSize = 1;
        tdata.iRadius = 2;
        if (m_parent) m_parent->SetToolData(&tdata);

        //show tool specific control
        StaticText4->Hide();
        SpinCtrl1->Hide();
        StaticText6->Show(true);
        SpinCtrl3->Show(true);
        StaticText5->Show(true);
        SpinCtrl2->Show(true);
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Hide();
    }
    else if ((iIndex == XPM_ID_TEXT_TOOL) && (bChecked))
    {
        StaticText4->Hide();
        SpinCtrl1->Hide();
        StaticText5->Hide();
        SpinCtrl2->Hide();
        StaticText6->Hide();
        SpinCtrl3->Hide();
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        HotSpotColourPicker->Hide();
        FontButton->Show(true);
        BackgroundButton->Show(true);
        //hide for now - will show them later
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Show(true);
        StaticText8->Show(true);
        SpinAngle->Show(true);
    }
    else if ((iIndex == XPM_ID_HOTSPOT_TOOL) && (bChecked))
    {
        StaticText4->Hide();
        SpinCtrl1->Hide();
        StaticText5->Hide();
        SpinCtrl2->Hide();
        StaticText6->Hide();
        SpinCtrl3->Hide();
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Show(true);
    }
    else
    {
        //hide all tools
        StaticText4->Hide();
        SpinCtrl1->Hide();
        StaticText5->Hide();
        SpinCtrl2->Hide();
        StaticText6->Hide();
        SpinCtrl3->Hide();
        LHairBrushButton->Hide();
        RHairBrushButton->Hide();
        CircleBrushButton->Hide();
        SquareBrushButton->Hide();
        FontButton->Hide();
        BackgroundButton->Hide();
        if (m_parent) m_parent->ShowCanvasWidgets(false);
        AlignmentPanel->Hide();
        StaticText8->Hide();
        SpinAngle->Hide();
        HotSpotColourPicker->Hide();
    }
}

/** Hide or Show specific tool controls - like style listbox for Brush tool...
  * In addition, the panel layout (positionning of the controls on the panel) will be updated
  * \param iIndex: the tool selected
  * \param bChecked: if true, the tool is Activated
  */
void XPMToolPanel::HideControlsAndDoLayout(int iIndex, bool bChecked)
{
    //hide other controls potentially shown and redo the layout
    HideControls(iIndex, bChecked);
    ToolPanelSizer->Layout();
    ToolPanelSizer->FitInside(ToolPanel);
}

void XPMToolPanel::OnSelectButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_SELECT_TOOL); else ToggleButtons(-1);

    //hide other controls potentially shown
    HideControlsAndDoLayout(XPM_ID_SELECT_TOOL, event.IsChecked());
}

void XPMToolPanel::OnLassoButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_LASSO_TOOL); else ToggleButtons(-1);

    //hide other controls potentially shown
    HideControlsAndDoLayout(XPM_ID_LASSO_TOOL, event.IsChecked());
}

void XPMToolPanel::OnHotSpotButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_HOTSPOT_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_HOTSPOT_TOOL, event.IsChecked());
}

void XPMToolPanel::OnPenButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_PEN_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_PEN_TOOL, event.IsChecked());
}

void XPMToolPanel::OnBrushButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked())
    {
        ToggleButtons(XPM_ID_BRUSH_TOOL);
        HideControlsAndDoLayout(XPM_ID_BRUSH_TOOL, true);
    }
    else
    {
        ToggleButtons(-1);
        //hide other controls potentially shown
        HideControlsAndDoLayout(XPM_ID_BRUSH_TOOL, false);
    }
}

void XPMToolPanel::OnPipetteButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_PIPETTE_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_PIPETTE_TOOL, event.IsChecked());
}

void XPMToolPanel::OnFillButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_FILL_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_FILL_TOOL, event.IsChecked());
}

void XPMToolPanel::OnLineButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_LINE_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_LINE_TOOL, event.IsChecked());
}

void XPMToolPanel::OnCurveButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_CURVE_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_CURVE_TOOL, event.IsChecked());
}

void XPMToolPanel::OnEraserButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_ERASER_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_ERASER_TOOL, event.IsChecked());
}

void XPMToolPanel::OnTextButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_TEXT_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_TEXT_TOOL, event.IsChecked());
}

void XPMToolPanel::OnRectangleButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_RECTANGLE_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_RECTANGLE_TOOL, event.IsChecked());
}

void XPMToolPanel::OnPolygonButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_POLYGON_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_POLYGON_TOOL, event.IsChecked());
}

void XPMToolPanel::OnEllipseButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_ELLIPSE_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_ELLIPSE_TOOL, event.IsChecked());
}

void XPMToolPanel::OnRRectButtonToggle(wxCommandEvent& event)
{
    //toggle all the other buttons
    if (event.IsChecked()) ToggleButtons(XPM_ID_ROUNDEDRECT_TOOL); else ToggleButtons(-1);
    HideControlsAndDoLayout(XPM_ID_ROUNDEDRECT_TOOL, event.IsChecked());
}

//--- EVENT HANDLERS FOR SUB-TOOLS OPTION -----------//

/** Event handler for Spin Control: the new value will update the size of the drawing tool
  */
void XPMToolPanel::OnSpinSizeChanged(wxSpinEvent& event)
{
    if (m_parent)
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iSize2 = event.GetPosition();
        m_parent->SetToolData(&tdata);
        SetToolCursor();
    }
}

/** Event handler for Spin Control: the new value will update the radius of the drawing tool
  */
void XPMToolPanel::OnSpinRadiusChanged(wxSpinEvent& event)
{
    if (m_parent)
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iRadius = event.GetPosition();
        m_parent->SetToolData(&tdata);
    }
}

/** Event handler for Spin Control: the new value will update the thickness of the drawing tool
  */
void XPMToolPanel::OnSpinThicknessChanged(wxSpinEvent& event)
{
    if (m_parent)
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iSize = event.GetPosition();
        m_parent->SetToolData(&tdata);
        SetToolCursor();
    }
}


/** A brush shape button has been toggled: Square Brush
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnSquareBrushButtonToggle(wxCommandEvent& event)
{
    if ((event.IsChecked()) && (m_parent))
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iStyle = XPM_BRUSH_STYLE_SQUARE;
        m_parent->SetToolData(&tdata);
        CircleBrushButton->SetValue(false);
        LHairBrushButton->SetValue(false);
        RHairBrushButton->SetValue(false);
    }
    else if (m_parent)
    {
        //to make sure that at least one button stays pushed
        SquareBrushButton->SetValue(true);
    }
}

/** A brush shape button has been toggled: Circle Brush
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnCircleBrushButtonToggle(wxCommandEvent& event)
{
    if ((event.IsChecked()) && (m_parent))
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iStyle = XPM_BRUSH_STYLE_CIRCLE;
        m_parent->SetToolData(&tdata);
        SquareBrushButton->SetValue(false);
        LHairBrushButton->SetValue(false);
        RHairBrushButton->SetValue(false);
    }
    else if (m_parent)
    {
        //to make sure that at least one button stays pushed
        CircleBrushButton->SetValue(true);
    }
}

/** A brush shape button has been toggled: Right Hair Brush (a segment)
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnRHairBrushButtonToggle(wxCommandEvent& event)
{
    if ((event.IsChecked()) && (m_parent))
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iStyle = XPM_BRUSH_STYLE_RIGHTHAIR;
        m_parent->SetToolData(&tdata);
        CircleBrushButton->SetValue(false);
        LHairBrushButton->SetValue(false);
        SquareBrushButton->SetValue(false);
    }
    else if (m_parent)
    {
        //to make sure that at least one button stays pushed
        RHairBrushButton->SetValue(true);
    }
}

/** A brush shape button has been toggled: Left Hair Brush (a segment)
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnLHairBrushButtonToggle(wxCommandEvent& event)
{
    if ((event.IsChecked()) && (m_parent))
    {
        ToolData tdata;
        m_parent->GetToolData(&tdata);
        tdata.iStyle = XPM_BRUSH_STYLE_LEFTHAIR;
        m_parent->SetToolData(&tdata);
        CircleBrushButton->SetValue(false);
        SquareBrushButton->SetValue(false);
        RHairBrushButton->SetValue(false);
    }
    else if (m_parent)
    {
        //to make sure that at least one button stays pushed
        LHairBrushButton->SetValue(true);
    }
}


//--- HANDLERS FOR TEXT EDITION RELATED SUB-TOOLS EVENTS ----///
/** The font for the text edition has been changed
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnFontButtonClick(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnFontButtonClick(event);
}

/** Change the background mode used by the text tool (opaque or transparent)
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnBackgroundButtonToggle(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnBackgroundButtonToggle(event);
}

/** The Text alignment changed to top-left
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnTopLeftSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnTopLeftSelect(event);
}

/** The Text alignment changed to top-center
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnTopCenterSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnTopCenterSelect(event);
}

/** The Text alignment changed to top-right
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnTopRightSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnTopRightSelect(event);
}

/** The Text alignment changed to center-left
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnCenterLeftSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnCenterLeftSelect(event);
}

/** The Text alignment changed to center-center
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnCenterCenterSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnCenterCenterSelect(event);
}

/** The Text alignment changed to center-right
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnCenterRightSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnCenterRightSelect(event);
}

/** The Text alignment changed to bottom-left
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnBottomLeftSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnBottomLeftSelect(event);
}

/** The Text alignment changed to bottom-center
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnBottomCenterSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnBottomCenterSelect(event);
}

/** The Text alignment changed to bottom-right
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnBottomRightSelect(wxCommandEvent& event)
{
    if (m_parent) m_parent->OnBottomRightSelect(event);
}

/** The Text orientation angle changed
  * \param event: the wxCommandEvent associated with the event
  */
void XPMToolPanel::OnSpinAngleChange(wxSpinEvent& event)
{
     if (m_parent) m_parent->OnSpinAngleChange(event);
}