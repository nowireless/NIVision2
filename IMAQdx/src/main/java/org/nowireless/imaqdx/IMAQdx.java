package org.nowireless.imaqdx;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class IMAQdx {
	
	private static int NULL = 0;
	
	public static enum IMAQdxBusType {
		IMAQdxBusTypeFireWire(0x31333934),
		IMAQdxBusTypeEthernet(0x69707634),
		IMAQdxBusTypeSimulator(0x2073696D),
		IMAQdxBusTypeDirectShow(0x64736877),
		IMAQdxBusTypeIP(0x4950636D),
		IMAQdxBusTypeSmartCam2(0x53436132),
		IMAQdxBusTypeUSB3Vision(0x55534233),
		IMAQdxBusTypeUVC(0x55564320),
		IMAQdxBusTypeGuard(0xFFFFFFFF);
		
		public final double value;
		
		private IMAQdxBusType(int value) {
			this.value = value;
		}
	}
	
	public static class IMAQdxCameraInformationArray {
		private final int size;
		private final long addr;
		private static native long _allocate(int size);
		private static native boolean _delete(int addr);
		private static native long _get(long addr, int element);
		
		public IMAQdxCameraInformationArray(int size) {
			this.addr = _allocate(size);
			this.size = size;
		}
		
		public IMAQdxCameraInformation get(int element) {
			if(element < 0 || size <= element) {
				return null;
			}
			return new IMAQdxCameraInformation(_get(addr, element));
		}
		
	}
	
	public static class IMAQdxCameraInformation {
		private native int _type(long addr);
		private native int _version(long addr);
		private native int _flags(long addr);
		private native int _serialNumberHi(long addr);
		private native int _serialNumberLo(long addr);
		private native int _busType(long addr);
		
		private native String _interfaceName(long addr);
		private native String _vendorName(long addr);
		private native String _modelName(long addr);
		private native String _cameraFileName(long addr);
		private native String _cameraAttributeUrl(long addr);
		
		private final long addr;
		
		private IMAQdxCameraInformation(long addr) {
			this.addr = addr;
		}
		
		public int type() {
			return _type(addr);
		}
		
		public String interfaceName() {
			return _interfaceName(addr);
		}
		
	}
	
	public static class IMAQdxException extends RuntimeException {
		private static final long serialVersionUID = 1L;

		public IMAQdxException(String str) {
			super(str);
		}
	}
	
	private static native int _IMAQdxEnumerateCameras(long informationArray, ByteBuffer count, boolean connectedOnly);
	
	public static int IMAQdxEnumerateCameras(IMAQdxCameraInformationArray infomation, boolean connectedOnly) {
		ByteBuffer countBuff = ByteBuffer.allocateDirect(4);
		int result = _IMAQdxEnumerateCameras(infomation == null ? NULL : infomation.addr, countBuff, connectedOnly);
		if(result != 0) {
			throw new IMAQdxException(Integer.toString(result));
		}
		countBuff.order(ByteOrder.LITTLE_ENDIAN);
//		System.out.println(countBuff.order());
		return countBuff.getInt(0);
	}
	
}
