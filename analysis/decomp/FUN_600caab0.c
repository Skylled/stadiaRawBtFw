// 600caab0  FUN_600caab0  size=140 bytes
// --- callers ---
//   6010149c FUN_6010149c
// --- callees ---
//   6013d360 thunk_EXT_FUN_00007d64
//   6013d1f0 thunk_EXT_FUN_000070b0
//   6013d000 thunk_EXT_FUN_00007dac


bool FUN_600caab0(uint param_1,uint param_2,undefined4 *param_3,int param_4)

{
  int *piVar1;
  bool bVar2;
  
  piVar1 = DAT_600cab3c;
  thunk_EXT_FUN_00007d64();
  if (*(char *)(*piVar1 + 200) != '\x02') {
    *(uint *)(*piVar1 + 0xc4) = *(uint *)(*piVar1 + 0xc4) & ~param_1;
    *(undefined1 *)(*piVar1 + 200) = 1;
    if (param_4 != 0) {
      thunk_EXT_FUN_000070b0(param_4);
      *DAT_600cab40 = 0x10000000;
      DataSynchronizationBarrier(0xf);
      InstructionSynchronizationBarrier(0xf);
    }
  }
  thunk_EXT_FUN_00007dac();
  thunk_EXT_FUN_00007d64();
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*piVar1 + 0xc4);
  }
  bVar2 = *(char *)(*piVar1 + 200) == '\x02';
  if (bVar2) {
    *(uint *)(*piVar1 + 0xc4) = *(uint *)(*piVar1 + 0xc4) & ~param_2;
  }
  *(undefined1 *)(*piVar1 + 200) = 0;
  thunk_EXT_FUN_00007dac();
  return bVar2;
}


