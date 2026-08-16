// 600b0444  FUN_600b0444  size=240 bytes
// --- callers ---
//   600afbd0 FUN_600afbd0
//   600ab8d4 FUN_600ab8d4
// --- callees ---
//   600cdd2c FUN_600cdd2c
//   601024d8 FUN_601024d8


void FUN_600b0444(short param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined1 auStack_60 [52];
  int local_2c;
  undefined1 local_6;
  undefined1 local_5;
  
  local_2c = 0;
  if (param_1 == 2) {
    FUN_600cdd2c(auStack_60,DAT_600b0534,param_2 & 0xffff);
  }
  else if (param_1 == 4) {
    FUN_600cdd2c(auStack_60,DAT_600b0538,param_2);
  }
  else if (param_1 == 0x10) {
    iVar1 = FUN_600cdd2c(auStack_60,DAT_600b053c,param_5._3_1_,param_5._2_1_,param_5._1_1_,
                         (undefined1)param_5,param_4 >> 0x18,param_4 >> 0x10 & 0xff,
                         param_4 >> 8 & 0xff,param_4 & 0xff);
    local_2c = local_2c + iVar1;
    local_5 = (undefined1)(param_3 >> 0x18);
    local_6 = (undefined1)(param_3 >> 0x10);
    FUN_600cdd2c(auStack_60 + local_2c,DAT_600b0540,local_5,local_6,param_3 >> 8 & 0xff,
                 param_3 & 0xff,param_2 >> 0x18,param_2 >> 0x10 & 0xff,param_2 >> 8 & 0xff,
                 param_2 & 0xff);
  }
  else {
    FUN_601024d8(auStack_60,DAT_600b0544,0xf);
  }
  return;
}


