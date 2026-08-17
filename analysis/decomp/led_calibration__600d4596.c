// 600d4596  led_calibration__600d4596  size=178 bytes
// src: led_calibration.cc
// --- callers ---
//   60051240 main__60051240
// --- callees ---
//   600653e0 FUN_600653e0
//   6010165c FUN_6010165c
//   6005ded8 FUN_6005ded8
//   6006b1d0 led_driver_lp5562__6006b1d0


/* src: led_calibration.cc */

void led_calibration__600d4596(void)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint in_fpscr;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  pcVar1 = DAT_6005e008;
  if (*DAT_6005e008 == '\0') {
    cVar2 = FUN_6005ded8();
    uVar3 = DAT_6005e00c;
    if (cVar2 != '\0') {
      return;
    }
    *pcVar1 = '\x01';
    FUN_6010165c(0x14,uVar3,0x35,DAT_6005e01c,*DAT_6005e018,*DAT_6005e014,*DAT_6005e010);
  }
  fVar4 = (float)VectorSignedToFloat((uint)*DAT_6005e018,(byte)(in_fpscr >> 0x16) & 3);
  uVar5 = VectorFloatToUnsigned(fVar4 * 1.0,3);
  fVar4 = (float)VectorSignedToFloat((uint)*DAT_6005e014,(byte)(in_fpscr >> 0x16) & 3);
  uVar6 = VectorFloatToUnsigned(fVar4 * 1.0,3);
  fVar4 = (float)VectorSignedToFloat((uint)*DAT_6005e010,(byte)(in_fpscr >> 0x16) & 3);
  uVar7 = VectorFloatToUnsigned(fVar4 * 1.0,3);
  uVar3 = FUN_600653e0();
  led_driver_lp5562__6006b1d0(uVar3,uVar5 & 0xff,uVar6 & 0xff,0,uVar7 & 0xff);
  return;
}


