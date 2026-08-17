// 600610d0  usb_host_worker__600610d0  size=168 bytes
// src: usb_host_worker.cc
// --- callers ---
// --- callees ---
//   6013d0e8 thunk_EXT_FUN_00006a74
//   60057e88 FUN_60057e88
//   6010165c FUN_6010165c
//   6013cfd8 thunk_EXT_FUN_00006bc8


/* src: usb_host_worker.cc */

void usb_host_worker__600610d0(void)

{
  int iVar1;
  undefined4 extraout_r3;
  bool bVar2;
  int local_18;
  undefined4 local_14;
  int iStack_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  iVar1 = DAT_600610f8;
  if (*(int *)(DAT_600610f4 + 0x3e78) == 2) {
                    /* WARNING: Could not recover jumptable at 0x6013d1f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_6013d1fc)(*(undefined4 *)(DAT_600610f4 + 16000));
    return;
  }
  if (*(int *)(DAT_600610f4 + 0x3e78) == 3) {
    FUN_60057e88(*(undefined4 *)(DAT_600610f8 + 0x9c));
    iStack_10 = *(int *)(iVar1 + 0x9c);
    local_14 = DAT_60065340;
    _local_c = CONCAT31((int3)((uint)extraout_r3 >> 8),9);
    if ((*(uint *)(DAT_60065348 + 4) & 0x1ff) == 0) {
      local_18 = iStack_10;
      iVar1 = thunk_EXT_FUN_00006a74(*(undefined4 *)(DAT_60065344 + 0xb0),&local_14,0);
      bVar2 = iVar1 == 1;
    }
    else {
      local_18 = 0;
      iVar1 = thunk_EXT_FUN_00006bc8(*(undefined4 *)(DAT_60065344 + 0xb0),&local_14,&local_18);
      bVar2 = iVar1 == 1;
      if (local_18 != 0) {
        *DAT_6006534c = 0x10000000;
        DataSynchronizationBarrier(0xf);
        InstructionSynchronizationBarrier(0xf);
      }
    }
    if (!bVar2) {
      FUN_6010165c(0x28,DAT_60065354,0x28,DAT_60065350);
    }
    return;
  }
  return;
}


