// 600c80fc  FUN_600c80fc  size=830 bytes
// --- callers ---
//   600ffd7a FUN_600ffd7a
// --- callees ---
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600c80fc(byte *param_1)

{
  byte local_18;
  byte local_17;
  byte local_16;
  byte local_15;
  byte local_14;
  byte local_13;
  byte local_12;
  byte local_11;
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_d;
  byte local_c;
  byte local_b;
  byte local_a;
  byte local_9;
  
  thunk_EXT_FUN_0000b572(&local_18,param_1,0x10);
  *param_1 = *(byte *)(DAT_600c838c + (uint)local_9) ^
             *(byte *)(DAT_600c838c + (uint)local_e) ^
             *(byte *)(DAT_600c8388 + (uint)local_13) ^ *(byte *)(DAT_600c8384 + (uint)local_18);
  param_1[1] = *(byte *)(DAT_600c838c + (uint)local_9) ^
               *(byte *)(DAT_600c8388 + (uint)local_e) ^
               *(byte *)(DAT_600c8384 + (uint)local_13) ^ *(byte *)(DAT_600c838c + (uint)local_18);
  param_1[2] = *(byte *)(DAT_600c8388 + (uint)local_9) ^
               *(byte *)(DAT_600c8384 + (uint)local_e) ^
               *(byte *)(DAT_600c838c + (uint)local_13) ^ *(byte *)(DAT_600c838c + (uint)local_18);
  param_1[3] = *(byte *)(DAT_600c8384 + (uint)local_9) ^
               *(byte *)(DAT_600c838c + (uint)local_e) ^
               *(byte *)(DAT_600c838c + (uint)local_13) ^ *(byte *)(DAT_600c8388 + (uint)local_18);
  param_1[4] = *(byte *)(DAT_600c838c + (uint)local_15) ^
               *(byte *)(DAT_600c838c + (uint)local_a) ^
               *(byte *)(DAT_600c8388 + (uint)local_f) ^ *(byte *)(DAT_600c8384 + (uint)local_14);
  param_1[5] = *(byte *)(DAT_600c838c + (uint)local_15) ^
               *(byte *)(DAT_600c8388 + (uint)local_a) ^
               *(byte *)(DAT_600c8384 + (uint)local_f) ^ *(byte *)(DAT_600c838c + (uint)local_14);
  param_1[6] = *(byte *)(DAT_600c8388 + (uint)local_15) ^
               *(byte *)(DAT_600c8384 + (uint)local_a) ^
               *(byte *)(DAT_600c838c + (uint)local_f) ^ *(byte *)(DAT_600c838c + (uint)local_14);
  param_1[7] = *(byte *)(DAT_600c8384 + (uint)local_15) ^
               *(byte *)(DAT_600c838c + (uint)local_a) ^
               *(byte *)(DAT_600c838c + (uint)local_f) ^ *(byte *)(DAT_600c8388 + (uint)local_14);
  param_1[8] = *(byte *)(DAT_600c838c + (uint)local_11) ^
               *(byte *)(DAT_600c838c + (uint)local_16) ^
               *(byte *)(DAT_600c8388 + (uint)local_b) ^ *(byte *)(DAT_600c8384 + (uint)local_10);
  param_1[9] = *(byte *)(DAT_600c838c + (uint)local_11) ^
               *(byte *)(DAT_600c8388 + (uint)local_16) ^
               *(byte *)(DAT_600c8384 + (uint)local_b) ^ *(byte *)(DAT_600c838c + (uint)local_10);
  param_1[10] = *(byte *)(DAT_600c8388 + (uint)local_11) ^
                *(byte *)(DAT_600c8384 + (uint)local_16) ^
                *(byte *)(DAT_600c838c + (uint)local_b) ^ *(byte *)(DAT_600c838c + (uint)local_10);
  param_1[0xb] = *(byte *)(DAT_600c8384 + (uint)local_11) ^
                 *(byte *)(DAT_600c838c + (uint)local_16) ^
                 *(byte *)(DAT_600c838c + (uint)local_b) ^ *(byte *)(DAT_600c8388 + (uint)local_10);
  param_1[0xc] = *(byte *)(DAT_600c8448 + (uint)local_d) ^
                 *(byte *)(DAT_600c8448 + (uint)local_12) ^
                 *(byte *)(DAT_600c8388 + (uint)local_17) ^ *(byte *)(DAT_600c8384 + (uint)local_c);
  param_1[0xd] = *(byte *)(DAT_600c8448 + (uint)local_d) ^
                 *(byte *)(DAT_600c8450 + (uint)local_12) ^
                 *(byte *)(DAT_600c844c + (uint)local_17) ^ *(byte *)(DAT_600c8448 + (uint)local_c);
  param_1[0xe] = *(byte *)(DAT_600c8450 + (uint)local_d) ^
                 *(byte *)(DAT_600c844c + (uint)local_12) ^
                 *(byte *)(DAT_600c8448 + (uint)local_17) ^ *(byte *)(DAT_600c8448 + (uint)local_c);
  param_1[0xf] = *(byte *)(DAT_600c844c + (uint)local_d) ^
                 *(byte *)(DAT_600c8448 + (uint)local_12) ^
                 *(byte *)(DAT_600c8448 + (uint)local_17) ^ *(byte *)(DAT_600c8450 + (uint)local_c);
  return;
}


