package org.nowireless.imaqdx;

import org.nowireless.imaqdx.IMAQdx.IMAQdxCameraInformation;
import org.nowireless.imaqdx.IMAQdx.IMAQdxCameraInformationArray;

public class CameraTest {
	public static void main(String[] args) {
		System.loadLibrary("IMAQdxJava");
		int count = IMAQdx.IMAQdxEnumerateCameras(null, false);
		System.out.println("JAVAc " + count);
		
		if(count > 0) {
			IMAQdxCameraInformationArray information = new IMAQdxCameraInformationArray(count);		
			count = IMAQdx.IMAQdxEnumerateCameras(information, false);
			System.out.println("JAVAc " + count);
			
			for(int i = 0; i < count; i++) {
				IMAQdxCameraInformation info = information.get(i);
				
//				System.out.println(info.type());
				System.out.println(info.interfaceName());
				
			}
		}		
//		System.out.println("Type: " +information.type());
//		System.out.println("Version: " +information.version());
//		System.out.println("serialNumberHi: " +information.serialNumberHi());
//		System.out.println("serialNumberLo: " +information.serialNumberLo());
//		System.out.println("Interface Name: " +information.interfaceName());

	}
}
