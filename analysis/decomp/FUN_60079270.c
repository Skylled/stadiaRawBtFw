// 60079270  FUN_60079270  size=210 bytes
// --- callers ---
// --- callees ---
//   600cbe5c FUN_600cbe5c
//   600db690 FUN_600db690
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   60101b76 FUN_60101b76
//   600db67c FUN_600db67c
//   6013d378 thunk_EXT_FUN_0000b532
//   6013d068 thunk_EXT_FUN_0000b52e
//   6005856c FUN_6005856c


undefined4 FUN_60079270(int param_1,undefined *param_2)

{
  char cVar1;
  bool bVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined *local_2c;
  undefined *local_28;
  undefined4 local_24;
  int local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  
  if (*(int *)(param_1 + 8) == 5) {
    DataMemoryBarrier(0x1b);
    do {
      ExclusiveAccess(DAT_60079344);
      cVar1 = *DAT_60079344;
      bVar2 = (bool)hasExclusiveAccess(DAT_60079344);
    } while (!bVar2);
    *DAT_60079344 = '\0';
    DataMemoryBarrier(0x1b);
    if (cVar1 != '\0') {
      iVar4 = thunk_EXT_FUN_0000b532(0x120);
      thunk_EXT_FUN_0000b5ba(iVar4,0,0x120);
      local_2c = (undefined *)0x0;
      iVar5 = *DAT_60079348;
      *DAT_60079348 = iVar4;
      if (iVar5 != 0) {
        thunk_EXT_FUN_0000b52e(iVar5,0x120);
      }
      FUN_600db67c(&local_2c);
      uVar6 = FUN_6005856c();
      local_2c = PTR_LAB_600d35aa_1_6007934c;
      local_28 = PTR_LAB_600790b4_1_60079350;
      iVar4 = FUN_600cbe5c(uVar6,PTR_LAB_600d35aa_1_6007934c,PTR_LAB_600790b4_1_60079350);
      puVar3 = PTR_s_Failed_to_add_log_callback_60079354;
      if (iVar4 == -1) {
        local_28 = param_2 + 0x19;
        local_1c = 0;
        local_1b = 0;
        param_2[0x19] = 0;
        local_24 = 0x100;
        local_20 = 0;
        *(undefined4 *)(param_2 + 8) = 2;
        param_2[0x10] = 1;
        *(undefined4 *)(param_2 + 0x14) = 1;
        param_2[0x18] = 1;
        local_2c = param_2;
        FUN_60101b76(&local_28,puVar3);
        local_2c[0x18] = local_20 != 0;
      }
    }
    DataMemoryBarrier(0x1b);
    *DAT_60079358 = *(undefined1 *)(param_1 + 0x10);
    DataMemoryBarrier(0x1b);
    if (*(char *)(param_1 + 0x10) != '\0') {
      FUN_600db690();
    }
    uVar6 = 2;
  }
  else {
    uVar6 = 0;
  }
  return uVar6;
}


