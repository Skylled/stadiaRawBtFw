// 600eec5a  FUN_600eec5a  size=192 bytes
// --- callers ---
//   60094a3c FUN_60094a3c
//   6009486c FUN_6009486c
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ee45a FUN_600ee45a


undefined1
FUN_600eec5a(int param_1,undefined2 param_2,undefined2 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined1 param_9)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 local_11;
  undefined4 local_4;
  
  local_11 = 0;
  if ((*(int *)(param_1 + 0x28) == 0) || (0x1d < *(byte *)(param_1 + 0x2e))) {
    local_11 = 0x83;
  }
  else {
    iVar2 = (uint)*(byte *)(param_1 + 0x2e) * 0x1c + *(int *)(param_1 + 0x28);
    *(char *)(param_1 + 0x2f) = *(char *)(param_1 + 0x2f) + '\x01';
    *(undefined2 *)(iVar2 + 0x14) = param_2;
    *(undefined2 *)(iVar2 + 0x16) = param_3;
    *(undefined1 *)(iVar2 + 0x18) = param_9;
    local_4 = param_4;
    uVar1 = FUN_600ee45a(param_1,param_4,param_5,param_6,param_7,param_8);
    *(undefined1 *)(iVar2 + 0x19) = uVar1;
    thunk_EXT_FUN_0000b572(iVar2,&local_4,0x14);
    *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + '\x01';
  }
  return local_11;
}


