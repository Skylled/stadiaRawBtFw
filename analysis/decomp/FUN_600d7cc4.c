// 600d7cc4  FUN_600d7cc4  size=24 bytes
// --- callers ---
//   6005d844 trigger_bug_report__6005d844
//   60051240 main__60051240
//   600d7d1c FUN_600d7d1c
// --- callees ---
//   600d995c FUN_600d995c


undefined1 FUN_600d7cc4(undefined4 param_1,uint3 param_2,undefined4 param_3)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = (uint)param_2;
  uStack_8 = param_3;
  FUN_600d995c((int)&uStack_c + 3);
  return uStack_c._3_1_;
}


