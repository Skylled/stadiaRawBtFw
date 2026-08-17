// 6006855c  battery_charger_bq25601__6006855c  size=56 bytes
// src: battery_charger_bq25601.cc
// --- callers ---
//   6005a010 FUN_6005a010
//   60051240 main__60051240
// --- callees ---
//   600cbb14 FUN_600cbb14
//   6010165c FUN_6010165c
//   6006849c FUN_6006849c


/* src: battery_charger_bq25601.cc */

bool battery_charger_bq25601__6006855c
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 local_10;
  int local_c;
  
  local_10 = param_3;
  local_c = param_4;
  cVar2 = FUN_6006849c(param_1,&local_c,param_3,param_4,param_1,param_2);
  iVar1 = local_c;
  local_10 = CONCAT31(local_10._1_3_,cVar2);
  if (cVar2 != '\0') {
    uVar3 = FUN_600cbb14(&local_10);
    FUN_6010165c(0x28,DAT_60068598,0xbb,DAT_60068594,uVar3);
  }
  return cVar2 == '\0' && iVar1 != 0;
}


