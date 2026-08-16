// 600ab620  FUN_600ab620  size=316 bytes
// --- callers ---
//   600fe146 FUN_600fe146
//   600f322e FUN_600f322e
//   600fe1ea FUN_600fe1ea
// --- callees ---
//   600af7c8 FUN_600af7c8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600afd84 FUN_600afd84
//   600afd28 FUN_600afd28
//   6006dbac FUN_6006dbac
//   600f6d9c FUN_600f6d9c
//   600afdf8 FUN_600afdf8
//   600ac438 FUN_600ac438
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined1 FUN_600ab620(undefined2 param_1,byte param_2,undefined1 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_9;
  
  local_9 = 0;
  iVar1 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  iVar2 = FUN_600afd28((char)param_1);
  if ((((iVar1 == 0) || (iVar2 == 0)) || (param_3 == (undefined1 *)0x0)) ||
     ((5 < param_2 || (param_2 == 0)))) {
    local_9 = 0x87;
  }
  else {
    iVar1 = FUN_600afd84(param_1);
    if (iVar1 == 0) {
      iVar1 = FUN_600afdf8(param_1);
      if (iVar1 == 0) {
        local_9 = 0x80;
      }
      else {
        *(undefined1 *)(iVar1 + 0x31) = 2;
        *(byte *)(iVar1 + 0x32) = param_2;
        *(undefined1 *)(iVar1 + 0x30) = *param_3;
        *(undefined2 *)(iVar1 + 0x2c) = 0;
        switch(param_2) {
        case 1:
        case 4:
          *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_3 + 2);
          *(undefined2 *)(iVar1 + 0x2a) = *(undefined2 *)(param_3 + 4);
          thunk_EXT_FUN_0000b572(iVar1 + 0x10,param_3 + 8,0x14);
          break;
        case 3:
          *(undefined2 *)(iVar1 + 0x28) = 0;
          uVar3 = FUN_6006dbac(0x18,DAT_600ab774,0x3b7);
          *(undefined4 *)(iVar1 + 0xc) = uVar3;
          thunk_EXT_FUN_0000b572(uVar3,param_3,0x18);
        case 2:
        case 5:
          thunk_EXT_FUN_0000b5ba(iVar1 + 0x10,0,0x14);
          *(undefined2 *)(iVar1 + 0x28) = *(undefined2 *)(param_3 + 2);
          if (param_2 == 5) {
            *(undefined2 *)(iVar1 + 0x2c) = *(undefined2 *)(param_3 + 4);
          }
        }
        iVar2 = FUN_600ac438(iVar1);
        if (iVar2 == 0) {
          local_9 = 0x80;
          FUN_600f6d9c(iVar1);
        }
      }
    }
    else {
      local_9 = 0x84;
    }
  }
  return local_9;
}


