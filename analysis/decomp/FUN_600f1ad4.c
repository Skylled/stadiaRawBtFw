// 600f1ad4  FUN_600f1ad4  size=96 bytes
// --- callers ---
//   600c2c04 FUN_600c2c04
// --- callees ---
//   600a44bc FUN_600a44bc
//   600f0836 FUN_600f0836


undefined4
FUN_600f1ad4(undefined4 param_1,char param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  undefined1 uStack_a;
  byte local_9;
  
  FUN_600f0836(param_1,&local_9,&uStack_a);
  if (((param_2 == '\x02') && ((local_9 & 2) == 0)) || ((param_2 == '\x01' && ((local_9 & 1) == 0)))
     ) {
    uVar1 = 0xe;
  }
  else {
    uVar1 = FUN_600a44bc(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}


