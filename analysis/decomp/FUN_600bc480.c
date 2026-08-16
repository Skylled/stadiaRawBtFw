// 600bc480  FUN_600bc480  size=236 bytes
// --- callers ---
//   600b8ba4 FUN_600b8ba4
//   600a5964 FUN_600a5964
//   600f76ac FUN_600f76ac
//   600b50d0 FUN_600b50d0
//   600b89b8 FUN_600b89b8
// --- callees ---
//   600aa340 FUN_600aa340
//   600bc5c4 FUN_600bc5c4
//   600f0836 FUN_600f0836
//   600f7f30 FUN_600f7f30
//   6009931c FUN_6009931c
//   600a1354 FUN_600a1354


undefined4 FUN_600bc480(char *param_1,char param_2)

{
  byte *pbVar1;
  int iVar2;
  undefined4 uVar3;
  char local_12;
  byte local_11;
  char *local_10;
  int local_c;
  
  local_10 = DAT_600bc56c;
  FUN_600f0836(param_1 + 4,&local_11,&local_12);
  if (param_2 == '\x02') {
    if (((*(byte *)(DAT_600bc570 + 0x81b) & 2) == 0) || ((local_11 & 2) == 0)) {
      uVar3 = 0;
    }
    else {
      param_1[0x33] = local_12;
      param_1[0x32] = '\x02';
      uVar3 = FUN_600f7f30(param_1);
    }
  }
  else {
    local_10 = DAT_600bc56c;
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      if ((((local_10 != param_1) && (*local_10 != '\0')) && (local_10[10] == '\x01')) &&
         (pbVar1 = (byte *)FUN_600a1354(), (*pbVar1 & 0x20) != 0)) {
        param_1[1] = '\x02';
        param_1[10] = '\0';
        iVar2 = FUN_6009931c(local_10 + 4,0,0);
        if (iVar2 == 1) {
          FUN_600aa340(param_1 + 0x44,2,10);
          return 1;
        }
      }
      local_10 = local_10 + 0xa4;
    }
    param_1[1] = '\x03';
    uVar3 = FUN_600bc5c4(param_1);
  }
  return uVar3;
}


