// 600fad26  FUN_600fad26  size=108 bytes
// --- callers ---
//   600fbdd0 FUN_600fbdd0
// --- callees ---
//   600fa7de FUN_600fa7de
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009ad00 FUN_6009ad00
//   600fb848 FUN_600fb848
//   600c1b74 FUN_600c1b74


void FUN_600fad26(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 auStack_19 [17];
  
  FUN_600fa7de(param_1,4,0,param_4,param_2);
  iVar1 = FUN_600c1b74(10,param_1);
  if (iVar1 != 0) {
    local_1c = *(undefined2 *)(param_1 + 0x1d6);
    local_1a = *(undefined1 *)(param_1 + 0x2b);
    local_20 = 0;
    thunk_EXT_FUN_0000b572(auStack_19,param_1 + 0x1d8,0x10);
    FUN_6009ad00(param_1 + 0x1d,0x40,&local_20,1);
  }
  FUN_600fb848(param_1,0);
  return;
}


