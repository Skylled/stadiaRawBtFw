// 600ab778  FUN_600ab778  size=272 bytes
// --- callers ---
//   600abdac FUN_600abdac
// --- callees ---
//   600af7c8 FUN_600af7c8
//   600afd28 FUN_600afd28
//   600afdf8 FUN_600afdf8
//   6006dbac FUN_6006dbac
//   600f6d9c FUN_600f6d9c
//   600afd84 FUN_600afd84
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ac438 FUN_600ac438


char FUN_600ab778(undefined2 param_1,char param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char local_9;
  
  local_9 = '\0';
  iVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  iVar2 = FUN_600afd28((char)param_1);
  if ((((iVar1 == 0) || (iVar2 == 0)) || (param_3 == 0)) ||
     (((param_2 != '\x02' && (param_2 != '\x03')) && (param_2 != '\x01')))) {
    local_9 = -0x79;
  }
  else {
    iVar1 = FUN_600afd84(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_600afdf8(param_1);
      if (iVar1 == 0) {
        local_9 = -0x80;
      }
      else {
        *(undefined1 *)(iVar1 + 0x31) = 3;
        *(char *)(iVar1 + 0x32) = param_2;
        *(undefined1 *)(iVar1 + 0x30) = *(undefined1 *)(param_3 + 8);
        uVar3 = FUN_6006dbac(0x262,DAT_600ab888,0x407);
        *(undefined4 *)(iVar1 + 0xc) = uVar3;
        if (*(int *)(iVar1 + 0xc) == 0) {
          local_9 = -0x80;
        }
        else {
          thunk_EXT_FUN_0000b572(*(undefined4 *)(iVar1 + 0xc),param_3,0x262);
          if (param_2 == '\x03') {
            *(undefined2 *)(iVar1 + 0x2e) = *(undefined2 *)(param_3 + 4);
            *(undefined2 *)(*(int *)(iVar1 + 0xc) + 4) = 0;
          }
          iVar2 = FUN_600ac438(iVar1);
          if (iVar2 == 0) {
            local_9 = -0x80;
          }
        }
        if (local_9 == -0x80) {
          FUN_600f6d9c(iVar1);
        }
      }
    }
    else {
      local_9 = -0x7c;
    }
  }
  return local_9;
}


