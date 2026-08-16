// 6009e098  FUN_6009e098  size=270 bytes
// --- callers ---
//   6009e4d0 FUN_6009e4d0
// --- callees ---
//   6013d168 thunk_EXT_FUN_0000b554
//   600f147c FUN_600f147c


byte FUN_6009e098(undefined4 param_1,char param_2)

{
  int iVar1;
  byte *pbVar2;
  undefined1 auStack_19 [5];
  int local_14;
  int local_10;
  undefined1 local_a;
  byte local_9;
  
  local_a = 0;
  local_9 = 0;
  local_10 = DAT_6009e1a8;
  local_14 = DAT_6009e1ac;
  if (*(char *)(DAT_6009e1b0 + 0x8d0) < '\0') {
    local_9 = 2;
  }
  if (((*(byte *)(DAT_6009e1b0 + 0x8d0) & 0x40) != 0) && ((param_2 == '\0' || (param_2 == '\x01'))))
  {
    local_9 = local_9 | 4;
  }
  if ((((*(char *)(DAT_6009e1a8 + 4) != '\x02') ||
       (iVar1 = thunk_EXT_FUN_0000b554(param_1,DAT_6009e1a8 + 5,6), iVar1 == 0)) &&
      (*(char *)(local_14 + 0x34) != '\0')) &&
     (pbVar2 = (byte *)FUN_600f147c(local_14 + 0x35,1,auStack_19), pbVar2 != (byte *)0x0)) {
    if (((*(byte *)(DAT_6009e1b0 + 0x1112) & 0x10) == 0) || ((*pbVar2 & 3) == 0)) {
      if (((*(byte *)(DAT_6009e1b0 + 0x1112) & 0x20) != 0) && ((*pbVar2 & 1) != 0)) {
        local_9 = local_9 | 1;
      }
    }
    else {
      local_9 = local_9 | 1;
    }
  }
  return local_9;
}


