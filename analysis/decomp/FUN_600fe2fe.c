// 600fe2fe  FUN_600fe2fe  size=308 bytes
// --- callers ---
// --- callees ---
//   600ef476 FUN_600ef476
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600ab778 FUN_600ab778
//   6013d3a0 thunk_EXT_FUN_0000b572
//   60094d24 FUN_60094d24
//   600eedee FUN_600eedee


void FUN_600fe2fe(undefined2 *param_1,int param_2)

{
  int iVar1;
  undefined1 auStack_280 [8];
  undefined1 local_278;
  char local_277;
  undefined4 local_274;
  undefined1 auStack_270 [2];
  short local_26e;
  undefined2 local_26c;
  undefined2 local_26a;
  undefined1 local_268;
  undefined1 auStack_267 [603];
  short local_c;
  char local_9;
  
  local_c = 0;
  local_9 = 0;
  thunk_EXT_FUN_0000b5ba(auStack_270,0,0x262);
  iVar1 = FUN_600ef476(param_1,param_2);
  if (iVar1 != 0) {
    local_c = FUN_600eedee(*(undefined4 *)(param_1 + 8),param_2 + 0xc,param_2 + 0x28,
                           *(undefined4 *)(param_2 + 0x40));
    if (local_c == 0) {
      local_9 = -0x7b;
    }
    else {
      local_26c = *(undefined2 *)(param_2 + 0x46);
      local_26a = *(undefined2 *)(param_2 + 0x48);
      local_268 = *(undefined1 *)(param_2 + 8);
      local_26e = local_c;
      if (*(int *)(param_2 + 0x4c) != 0) {
        thunk_EXT_FUN_0000b572
                  (auStack_267,*(undefined4 *)(param_2 + 0x4c),*(undefined2 *)(param_2 + 0x48));
      }
      local_9 = FUN_600ab778(*param_1,*(undefined1 *)(param_2 + 0x44),auStack_270);
    }
    if (local_9 != '\0') {
      thunk_EXT_FUN_0000b5ba(auStack_280,0,0x10);
      local_277 = local_9;
      local_278 = 3;
      local_274 = 0;
      FUN_60094d24(param_1,0x1d10,auStack_280);
    }
  }
  return;
}


