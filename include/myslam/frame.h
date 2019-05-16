#ifndef FRAME_H
#define FRAME_H

namespace myslam{
	class Frame{
	public:

		// data member
		typedef std::shared_ptr<Frame> Ptr;
		unsigned long id_;  // id of this frame
		double time_stamp_; // when it is recorded
		SE3 T_c_w_;         // transform from world to camera
		Camera::Ptr camera_; // RGBD camera model
		Mat color_, depth_; // color and depth image

		
		Frame();
		Frame(long id, double time_stame=0, SE3 T_c_w=SE3(), Camera::Ptr camera=nullptr, Mat color=Mat(), Mat depth=Mat());
		~Frame();

		// factory function
		static Frame::Ptr createFrame();

		// find the depth in depth map
		double findDepth(const cv::KeyPoint& kp);

		// get camera center
		Vector3d getCameraCenter() const;

		// check if a point is in this frame
		bool isInFrame(const Vector3d& pt_world);
	};
}

#endif // FRAME_H