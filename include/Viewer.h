/**
* This file is part of the Collaborative Visual SLAM Extension for ORB-SLAM2:
* "Collaborative Visual SLAM using Compressed Feature Exchange"
* Copyright (C) 2017-2018 Dominik Van Opdenbosch <dominik dot van-opdenbosch at tum dot de>
* Chair of Media Technology, Technical University of Munich
* For more information see <https://d-vo.github.io/>
*
* ORB-SLAM2 and the collaborative extension is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM2 and the collaborative extension is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with the ORB-SLAM2 collaborative extension. If not, see <http://www.gnu.org/licenses/>.
*
* The extension is built upon ORB-SLAM2:
* ORB-SLAM2 Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/raulmur/ORB_SLAM2>
*/


#ifndef VIEWER_H
#define VIEWER_H

#include "FrameDrawer.h"
#include "MapDrawer.h"
#include "Tracking.h"
#include "System.h"

#include <mutex>

namespace CORB_SLAM2
{

class Tracking;
class FrameDrawer;
class MapDrawer;
class System;

class Viewer
{
public:
    Viewer(System* pSystem, std::vector<FrameDrawer*> vpFrameDrawer, const string &strSettingPath);

    // Main thread function. Draw points, keyframes, the current camera pose and the last processed
    // frame. Drawing is refreshed according to the camera fps. We use Pangolin.
    void Run();

    void RequestFinish();

    void RequestStop();

    bool isFinished();

    bool isStopped();

    void Release();

private:

    bool Stop();

    System* mpSystem;
    std::vector<FrameDrawer*> mvpFrameDrawer;

    // 1/fps in ms
    double mT;
    float mImageWidth, mImageHeight;



    bool CheckFinish();
    void SetFinish();
    bool mbFinishRequested;
    bool mbFinished;
    int mnRonbotId;
    std::mutex mMutexFinish;

    bool mbStopped;
    bool mbStopRequested;
    std::mutex mMutexStop;

};

}


#endif // VIEWER_H
	
