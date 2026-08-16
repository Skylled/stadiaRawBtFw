// 600ac524  FUN_600ac524  size=382 bytes
// --- callers ---
//   600ac9a4 FUN_600ac9a4
//   600f484a FUN_600f484a
//   600f3aae FUN_600f3aae
//   600f4920 FUN_600f4920
//   600acddc FUN_600acddc
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600b00b4 FUN_600b00b4
//   600af9a0 FUN_600af9a0
//   600ffada FUN_600ffada
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600ac524(undefined4 *param_1)

{
  undefined2 local_270;
  undefined2 local_26e;
  undefined2 local_26c;
  undefined2 local_268;
  undefined2 local_264;
  undefined2 local_25c;
  undefined2 local_25a;
  undefined2 local_258;
  undefined1 auStack_256 [588];
  char local_a;
  undefined1 local_9;
  
  local_9 = *(undefined1 *)(DAT_600ac6a4 + (uint)*(byte *)((int)param_1 + 0x32));
  if ((*(ushort *)((int)param_1 + 0x2a) < *(ushort *)(param_1 + 10)) ||
     (*(short *)(param_1 + 10) == 0)) {
    FUN_600b00b4(param_1,0,0);
  }
  else {
    thunk_EXT_FUN_0000b5ba(&local_270,0,0x264);
    local_26e = *(undefined2 *)(param_1 + 10);
    local_26c = *(undefined2 *)((int)param_1 + 0x2a);
    if (*(short *)(DAT_600ac6a8 + (uint)*(byte *)((int)param_1 + 0x32) * 2) != 0) {
      local_268 = 2;
      local_264 = *(undefined2 *)(DAT_600ac6a8 + (uint)*(byte *)((int)param_1 + 0x32) * 2);
    }
    if (*(char *)((int)param_1 + 0x32) == '\x02') {
      local_270 = 2;
      local_26c = *(undefined2 *)(DAT_600ac6a8 + (uint)*(byte *)((int)param_1 + 0x32) * 2);
      local_25c = *(undefined2 *)(param_1 + 10);
      local_25a = *(undefined2 *)((int)param_1 + 0x2a);
      local_258 = *(undefined2 *)(param_1 + 4);
      if (*(short *)(param_1 + 4) == 4) {
        local_258 = 0x10;
        FUN_600af9a0(auStack_256,param_1[5]);
      }
      else {
        thunk_EXT_FUN_0000b572(auStack_256,param_1 + 5,*(undefined2 *)(param_1 + 4));
      }
    }
    local_a = FUN_600ffada(*param_1,*(undefined2 *)((int)param_1 + 0x26),local_9,&local_270);
    if ((local_a != '\0') && (local_a != -0x7a)) {
      FUN_600b00b4(param_1,0x85,0);
    }
  }
  return;
}


