// 600684e0  battery_charger_bq25601__600684e0  size=58 bytes
// src: battery_charger_bq25601.cc
// --- callers ---
//   600686e4 FUN_600686e4
// --- callees ---
//   6010165c FUN_6010165c
//   600d8322 FUN_600d8322


/* src: battery_charger_bq25601.cc */

uint battery_charger_bq25601__600684e0
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  puVar1 = DAT_6006851c;
  uVar2 = FUN_600d8322(param_1,*DAT_6006851c,param_3,param_4,param_1,param_2);
  if ((uVar2 & 0xff) == 0) {
    uVar2 = (**(byte **)puVar1[1] & 0x7f) >> 3;
    if (uVar2 == 2) {
      uVar2 = 0;
    }
    else {
      FUN_6010165c(0x28,DAT_60068520,0xa7,DAT_60068524,uVar2,2);
      uVar2 = 5;
    }
  }
  return uVar2;
}


