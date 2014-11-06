/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package org.doubango.tinyWRAP;

public class MediaContent {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected MediaContent(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(MediaContent obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPJNI.delete_MediaContent(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public String getType() {
    return tinyWRAPJNI.MediaContent_getType(swigCPtr, this);
  }

  public long getDataLength() {
    return tinyWRAPJNI.MediaContent_getDataLength(swigCPtr, this);
  }

  public long getData(java.nio.ByteBuffer pOutput, long nMaxsize) {
    return tinyWRAPJNI.MediaContent_getData(swigCPtr, this, pOutput, nMaxsize);
  }

  public static MediaContent parse(java.nio.ByteBuffer pData, long nSize, String pType) {
    long cPtr = tinyWRAPJNI.MediaContent_parse__SWIG_0(pData, nSize, pType);
    return (cPtr == 0) ? null : new MediaContent(cPtr, true);
  }

  public static MediaContentCPIM parse(java.nio.ByteBuffer pData, long nSize) {
    long cPtr = tinyWRAPJNI.MediaContent_parse__SWIG_1(pData, nSize);
    return (cPtr == 0) ? null : new MediaContentCPIM(cPtr, true);
  }

  public long getPayloadLength() {
    return tinyWRAPJNI.MediaContent_getPayloadLength(swigCPtr, this);
  }

  public long getPayload(java.nio.ByteBuffer pOutput, long nMaxsize) {
    return tinyWRAPJNI.MediaContent_getPayload(swigCPtr, this, pOutput, nMaxsize);
  }

}
