/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package edu.wpi.first.wpilibj;

public class Timer {
 
	/**
   * Pause the thread for a specified time. Pause the execution of the thread
   * for a specified period of time given in seconds. Motors will continue to
   * run at their last assigned values, and sensors will continue to update.
   * Only the task containing the wait will pause until the wait time is
   * expired.
   *
   * @param seconds Length of time to pause
   */
  public static void delay(final double seconds) {
	  try {
		Thread.sleep(Math.round(seconds * 1000));
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
  }
}
