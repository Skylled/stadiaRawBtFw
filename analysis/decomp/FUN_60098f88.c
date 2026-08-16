// 60098f88  FUN_60098f88  size=508 bytes
// --- callers ---
//   600b5720 FUN_600b5720
//   600b56aa FUN_600b56aa
//   600b89b8 FUN_600b89b8
//   600a6d70 FUN_600a6d70
// --- callees ---
//   600b12e4 FUN_600b12e4
//   600999bc FUN_600999bc
//   6009feb8 FUN_6009feb8
//   60098ec8 FUN_60098ec8
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6009bf1c FUN_6009bf1c
//   600f8ba8 FUN_600f8ba8
//   600b2ad0 FUN_600b2ad0
//   600a36e4 FUN_600a36e4
//   600bc7e8 FUN_600bc7e8
//   600f01cc FUN_600f01cc
//   60099c0c FUN_60099c0c
//   600b2a4c FUN_600b2a4c
//   600a8494 FUN_600a8494


void FUN_60098f88(undefined4 param_1,int param_2,int param_3,undefined2 param_4,char param_5,
                 char param_6)

{
  byte bVar1;
  undefined2 *puVar2;
  int iVar3;
  byte local_d;
  undefined2 *local_c;
  
  if (param_5 == -1) {
    param_5 = FUN_600f8ba8(param_1);
  }
  puVar2 = (undefined2 *)FUN_60098ec8(param_1,param_6);
  if (puVar2 == (undefined2 *)0x0) {
    local_c = DAT_60099184;
    for (local_d = 0; local_d < 4; local_d = local_d + 1) {
      if (*(char *)(local_c + 0x94) == '\0') {
        *(undefined1 *)(local_c + 0x94) = 1;
        *local_c = param_4;
        *(char *)((int)local_c + 0x129) = param_5;
        *(undefined1 *)(local_c + 0x95) = 0;
        thunk_EXT_FUN_0000b572(local_c + 3,param_1,6);
        *(char *)(local_c + 0x97) = param_6;
        if (param_6 == '\x02') {
          FUN_6009bf1c(param_1,DAT_60099188);
        }
        *(undefined1 *)((int)local_c + 299) = 0;
        FUN_600a36e4(local_d);
        if (param_2 != 0) {
          thunk_EXT_FUN_0000b572(local_c + 6,param_2,3);
        }
        if (param_3 != 0) {
          thunk_EXT_FUN_0000b572((int)local_c + 0xf,param_3,10);
        }
        iVar3 = FUN_6009feb8(param_4);
        if (param_6 == '\x01') {
          FUN_600b2a4c(*local_c);
          FUN_600b2ad0(*local_c);
        }
        if ((((iVar3 != 0) && (param_6 == '\x01')) && (*(char *)(iVar3 + 0x4f) != '\0')) &&
           (*(byte *)(iVar3 + 0x4f) < 4)) {
          thunk_EXT_FUN_0000b572(local_c + 0x87,iVar3 + 0x37,(uint)*(byte *)(iVar3 + 0x4f) << 3);
          *(undefined1 *)(local_c + 0x93) = *(undefined1 *)(iVar3 + 0x4f);
          bVar1 = *(byte *)(iVar3 + 0x59);
          FUN_600a8494(local_c,iVar3);
          if ((bVar1 & 8) != 0) {
            FUN_600bc7e8(iVar3 + 0x10);
          }
          FUN_60099c0c(local_c);
          return;
        }
        if ((iVar3 == 0) || (param_6 != '\x02')) {
          FUN_600999bc(*local_c);
          return;
        }
        FUN_600f01cc(iVar3,local_c + 0x9b,local_c + 0x9e);
        if (((*(byte *)(DAT_6009918c + 0x831) & 8) == 0) && (param_5 != '\0')) {
          FUN_60099c0c(local_c);
          return;
        }
        FUN_600b12e4(*local_c);
        return;
      }
      local_c = local_c + 0xa6;
    }
  }
  else {
    *puVar2 = param_4;
    *(char *)((int)puVar2 + 0x129) = param_5;
    *(char *)(puVar2 + 0x97) = param_6;
  }
  return;
}


