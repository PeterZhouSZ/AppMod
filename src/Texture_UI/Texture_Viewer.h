#ifndef Texture_Viewer_H
#define Texture_Viewer_H

#include "BasicViewer.h"

#include <memory>

class MainCanvasViewer;
class VectorFieldViewer;
class QMouseEvent;
class QKeyEvent;
class QResizeEvent;
class Texture_Viewer : public BasicViewer
{
	Q_OBJECT
public:
	Texture_Viewer(QWidget *widget);
	~Texture_Viewer();

  void updateBuffer();
  void updateColorBuffer();
  void toggleLightball();
  void resetCamera();
  inline void setShowTrackball(bool state) { show_trackball = state; };

  void updateCamera();
  void clear_selection();
  void set_edit_mode(int);
  bool get_edit_mode();
  bool draw_mesh_points();
protected:
  virtual void draw();
  virtual void init();
  void drawTrackBall();
  void drawActors();
  //void drawCrestLines();

private:
  void drawCornerAxis();
  void setWheelandMouse();
  void mousePressEvent(QMouseEvent *e);
  void mouseMoveEvent(QMouseEvent *e);
  void mouseReleaseEvent(QMouseEvent *e);
  void mouseDoubleClickEvent(QMouseEvent * event);
  void wheelEvent(QWheelEvent* e);
  void keyPressEvent(QKeyEvent *e);
  void draw_points_under_mouse();

private slots:
void resizeEvent(QResizeEvent*);
private:

  bool wireframe_;
  bool show_trackball;
  bool play_lightball;

  bool m_left_button_down_;
  bool m_right_buttonm_down_;
  int  m_edit_mode_;


  std::vector<qglviewer::Vec>	m_points_ubder_mouse_;
private:

};

#endif