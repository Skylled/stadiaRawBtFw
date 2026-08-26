// 600d7cdc  FUN_600d7cdc  size=64 bytes
// --- callers ---
//   6005d844 trigger_bug_report__6005d844
//   6005969c FUN_6005969c
//   6007053c external_controller__6007053c
// --- callees ---
//   600d72ec FUN_600d72ec
//   600d9934 FUN_600d9934


char FUN_600d7cdc(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  undefined4 extraout_r2;
  undefined4 uStack_c;
  
  uStack_c._3_1_ = (char)((uint)param_2 >> 0x18);
  uStack_c._0_2_ = (ushort)param_2;
  uStack_c._0_3_ = (uint3)(ushort)uStack_c;
  cVar1 = FUN_600d9934((int)&uStack_c + 2);
  uStack_c = uStack_c & 0xffffff;
  if (cVar1 == '\0') {
    cVar1 = uStack_c._2_1_;
  }
  else {
    cVar1 = '\0';
  }
  uStack_c._0_3_ = CONCAT12(cVar1,(ushort)uStack_c);
  uStack_c = (uint)(uint3)uStack_c;
  if ((cVar1 == '\0') &&
     (cVar2 = FUN_600d72ec(0x16,(int)&uStack_c + 3,extraout_r2,0,param_1), cVar2 == '\0')) {
    cVar1 = uStack_c._3_1_;
  }
  return cVar1;
}


