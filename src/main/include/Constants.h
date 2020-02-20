/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

// VERY important for auto constants
#include "units/units.h"
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


namespace DriveConstants
{
    // AUTO CONSTANTS
    // placeholder values until measured with FRC Characterization Tool - voltage
    constexpr auto ks = 0.22_V;
    constexpr auto kv = 1.98 * 1_V * 1_s / 1_m;
    constexpr auto ka = 0.2 * 1_V * 1_s * 1_s / 1_m;
    constexpr double kPDriveVel = 8.5;
    // distance between wheels for differential drive
    constexpr auto kTrackwidth = 0.609_m;
    // max speed/accelerations
    constexpr auto kMaxSpeed = 4_mps;
    constexpr auto kMaxAcceleration = 3_mps_sq;
    // RAMSETE follower values
    constexpr double kRamseteB = 2;
    constexpr double kRamseteZeta = 0.7;
    constexpr bool kGyroReversed = true;
}

#endif //CONSTANTS_H