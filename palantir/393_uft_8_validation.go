func validUtf8(data []int) bool {
		// represents how many bytes to be read for the character
        numberOfBytes := 0
        for i := 0; i < len(data); i++ {
                // expect starting of the new character
                if numberOfBytes == 0 {
                        switch {
						// single byte character
                        case data[i]&0x80 == 0:
                                continue
						// two bytes character
                        case (data[i]&0xC0 == 0xC0) && (data[i]&0x20 == 0):
                                numberOfBytes = 1
						// three bytes character
                        case (data[i]&0xE0 == 0xE0) && (data[i]&0x10 == 0):
                                numberOfBytes = 2
						// four bytes character
                        case (data[i]&0xF0 == 0xF0) && (data[i]&0x08 == 0):
                                numberOfBytes = 3
						// if no match - invalid
                        default:
                                return false
                        }
                } else {
						// if the first bit is not set or second bit is not zero
                        if !((data[i]&0x80 == 0x80) && (data[i]&0x40 == 0)) {
                                return false
                        }
                        numberOfBytes--
                }
        }
		// there could be a case when not enough bytes existed in `data` for multibytes character
        return numberOfBytes == 0
}