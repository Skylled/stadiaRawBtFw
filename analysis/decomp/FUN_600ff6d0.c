// 600ff6d0  FUN_600ff6d0  size=72 bytes
// --- callers ---
//   600c57fc FUN_600c57fc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b3ec0 FUN_600b3ec0


undefined4 FUN_600ff6d0(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_70 [6];
  byte local_6a;
  
  thunk_EXT_FUN_0000b572(auStack_70,param_2,0x68);
  if (0x20 < local_6a) {
    local_6a = 0x20;
  }
  iVar1 = FUN_600b3ec0(param_1,auStack_70);
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


