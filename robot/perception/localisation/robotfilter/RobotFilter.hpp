/*
Copyright 2014 The University of New South Wales (UNSW).

This file is part of the 2014 team rUNSWift RoboCup entry. You may
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version as
modified below. As the original licensors, we add the following
conditions to that license:

In paragraph 2.b), the phrase "distribute or publish" should be
interpreted to include entry into a competition, and hence the source
of any derived work entered into a competition must be made available
to all parties involved in that competition under the terms of this
license.

In addition, if the authors of a derived work publish any conference
proceedings, journal articles or other academic papers describing that
derived work, then appropriate academic citations to the original work
must be included in that publication.

This rUNSWift source is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License along
with this source code; if not, write to the Free Software Foundation,
Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#pragma once

#include <vector>
#include <Eigen/Eigen>
#include "types/AbsCoord.hpp"
#include "types/RRCoord.hpp"
#include "types/Odometry.hpp"
#include "types/RobotInfo.hpp"
#include "types/GroupedRobots.hpp"
#include "types/RobotFilterUpdate.hpp"
#include "perception/localisation/LocalisationDefs.hpp"

/**
 * Robot filter deals with deciding what observations should be placed into
 * what groups depending on whether it is possible to merge it into that group.
 */
class RobotFilter {
   public:
      std::vector<RobotObstacle> update(const RobotFilterUpdate &update);

   private:

      std::vector<RobotObstacle> filteredRobots;
      std::vector<RobotObstacle> generateRobotObstacles() const;
      std::vector<GroupedRobots> groupedRobots;
};

