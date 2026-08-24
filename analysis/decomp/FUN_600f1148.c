// 600f1148  FUN_600f1148  size=468 bytes
// --- callers ---
//   6009c01c FUN_6009c01c
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600f0836 FUN_600f0836
//   6009ff18 FUN_6009ff18
//   60098718 FUN_60098718
//   600b1090 FUN_600b1090


undefined1 FUN_600f1148(char param_1,byte *param_2,char param_3)

{
  int iVar1;
  undefined1 uStack_19;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 local_11;
  int local_10;
  undefined1 local_9;
  
  local_10 = FUN_6009ff18(param_2);
  local_11 = 0;
  local_9 = 0;
  local_18 = 0;
  local_14 = 0;
  if ((local_10 == 0) || ((*(byte *)(local_10 + 0xe4) & 2) == 0)) {
    FUN_600f0836(param_2,&uStack_19,&local_11);
    if (param_3 == '\0') {
      local_9 = FUN_600b1090(local_11,param_2);
    }
    else {
      local_9 = FUN_60098718(local_11,param_2,param_3);
    }
  }
  else if (param_1 == '\0') {
    if ((*(char *)(local_10 + 0x6a) == '\0') || ((*param_2 & 0xc0) != 0x40)) {
      if (param_3 == '\0') {
        local_9 = FUN_600b1090(*(undefined1 *)(local_10 + 0x6a),param_2);
      }
      else {
        local_9 = FUN_60098718(*(undefined1 *)(local_10 + 0x6a),param_2,param_3);
      }
      *(byte *)(local_10 + 0x72) = *(byte *)(local_10 + 0x72) & 0xfe;
    }
    iVar1 = thunk_EXT_FUN_0000b554(local_10 + 0x6c,&local_18,6);
    if ((iVar1 != 0) && (iVar1 = thunk_EXT_FUN_0000b554(local_10 + 0x6c,param_2,6), iVar1 != 0)) {
      if (param_3 == '\0') {
        local_9 = FUN_600b1090(*(undefined1 *)(local_10 + 0x6b),local_10 + 0x6c);
      }
      else {
        local_9 = FUN_60098718(*(undefined1 *)(local_10 + 0x6b),local_10 + 0x6c,param_3);
      }
      *(byte *)(local_10 + 0x72) = *(byte *)(local_10 + 0x72) & 0xfe;
    }
  }
  else if ((*(char *)(local_10 + 0x6a) == '\0') || ((*param_2 & 0xc0) != 0x40)) {
    local_9 = FUN_60098718(*(undefined1 *)(local_10 + 0x6a),param_2,param_3);
    *(byte *)(local_10 + 0x72) = *(byte *)(local_10 + 0x72) | 1;
  }
  else {
    iVar1 = thunk_EXT_FUN_0000b554(local_10 + 0x6c,&local_18,6);
    if (iVar1 != 0) {
      local_9 = FUN_60098718(*(undefined1 *)(local_10 + 0x6b),local_10 + 0x6c,param_3);
      *(byte *)(local_10 + 0x72) = *(byte *)(local_10 + 0x72) | 1;
    }
  }
  return local_9;
}


