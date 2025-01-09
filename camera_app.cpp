#include <wx/wx.h>
#include <opencv2/opencv.hpp>

class CameraFrame : public wxFrame {
public:
    CameraFrame() : wxFrame(nullptr, wxID_ANY, "Camera App", wxDefaultPosition, wxSize(800, 600)) {
        // Setup panel and sizer
        wxPanel* panel = new wxPanel(this, wxID_ANY);
        wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

        // Create a wxStaticBitmap to display the camera feed
        cameraView = new wxStaticBitmap(panel, wxID_ANY, wxBitmap(wxSize(640, 480)));
        sizer->Add(cameraView, 1, wxEXPAND | wxALL, 10);

        panel->SetSizer(sizer);

        // Start the timer to update the camera feed
        cameraTimer = new wxTimer(this);
        Bind(wxEVT_TIMER, &CameraFrame::OnCameraUpdate, this);
        cameraTimer->Start(30); // 30 ms for ~33 FPS

        // Open the camera using OpenCV
        if (!camera.open(0)) { // Open default camera
            wxMessageBox("Failed to open camera", "Error", wxICON_ERROR);
        }
    }

    ~CameraFrame() {
        camera.release(); // Release the camera
        cameraTimer->Stop();
    }

private:
    wxStaticBitmap* cameraView;
    wxTimer* cameraTimer;
    cv::VideoCapture camera;

    void OnCameraUpdate(wxTimerEvent&) {
        if (camera.isOpened()) {
            cv::Mat frame;
            camera >> frame; // Capture frame

            if (!frame.empty()) {
                cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB); // Convert to RGB
                wxImage image(frame.cols, frame.rows, frame.data, true);
                cameraView->SetBitmap(wxBitmap(image)); // Update camera view
            }
        }
    }
};

class CameraApp : public wxApp {
public:
    virtual bool OnInit() {
        CameraFrame* frame = new CameraFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(CameraApp);
