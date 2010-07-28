/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.39
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class SMSEncoder : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal SMSEncoder(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(SMSEncoder obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~SMSEncoder() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        tinyWRAPPINVOKE.delete_SMSEncoder(swigCPtr);
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
    }
  }

  public static RPMessage encodeSubmit(int mr, string smsc, string destination, string ascii) {
    IntPtr cPtr = tinyWRAPPINVOKE.SMSEncoder_encodeSubmit(mr, smsc, destination, ascii);
    RPMessage ret = (cPtr == IntPtr.Zero) ? null : new RPMessage(cPtr, true);
    return ret;
  }

  public static RPMessage encodeDeliver(int mr, string smsc, string originator, string ascii) {
    IntPtr cPtr = tinyWRAPPINVOKE.SMSEncoder_encodeDeliver(mr, smsc, originator, ascii);
    RPMessage ret = (cPtr == IntPtr.Zero) ? null : new RPMessage(cPtr, true);
    return ret;
  }

  public static RPMessage encodeACK(int mr, string smsc, string destination, bool forSUBMIT) {
    IntPtr cPtr = tinyWRAPPINVOKE.SMSEncoder_encodeACK(mr, smsc, destination, forSUBMIT);
    RPMessage ret = (cPtr == IntPtr.Zero) ? null : new RPMessage(cPtr, true);
    return ret;
  }

  public static RPMessage encodeError(int mr, string smsc, string destination, bool forSUBMIT) {
    IntPtr cPtr = tinyWRAPPINVOKE.SMSEncoder_encodeError(mr, smsc, destination, forSUBMIT);
    RPMessage ret = (cPtr == IntPtr.Zero) ? null : new RPMessage(cPtr, true);
    return ret;
  }

  public static SMSData decode(byte[] data, uint size, bool MobOrig) {
    IntPtr cPtr = tinyWRAPPINVOKE.SMSEncoder_decode(data, size, MobOrig);
    SMSData ret = (cPtr == IntPtr.Zero) ? null : new SMSData(cPtr, true);
    return ret;
  }

}
